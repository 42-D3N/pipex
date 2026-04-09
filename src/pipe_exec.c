/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:37:36 by tle-pape          #+#    #+#             */
/*   Updated: 2025/01/30 13:52:42 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	pipe_init(t_pipex dat)
{
	int	i;

	i = 0;
	dat.pipe = ft_calloc((dat.cmd_index_max - 1) * 2, sizeof(int));
	while (i < dat.cmd_index_max - 1)
	{
		if (pipe(dat.pipe + (2 * i)) == -1)
			handle_error("Error with pipe creation", dat, 2);
		i++;
	}
	return (dat);
}

t_pipex	set_pipe(t_pipex dat, int index)
{
	if (index == 0)
	{
		dup2(dat.infile, STDIN_FILENO);
		dup2(dat.pipe[1], STDOUT_FILENO);
	}
	else if (index == dat.cmd_index_max - 1)
	{
		dup2(dat.pipe[2 * (index - 1)], STDIN_FILENO);
		dup2(dat.outfile, STDOUT_FILENO);
	}
	else
	{
		dup2(dat.pipe[2 * (index - 1)], STDIN_FILENO);
		dup2(dat.pipe[2 * index + 1], STDOUT_FILENO);
	}
	return (dat);
}

void	forking(t_pipex dat, int index)
{
	char	**args;
	char	*cmd;

	args = ft_split(dat.cmds[index], ' ');
	cmd = handle_path(dat.envp, args[0]);
	if (!cmd)
	{
		free(cmd);
		free_arr(args);
		handle_error("Error : Command not found / Perms not right", dat, 127);
	}
	dat = set_pipe(dat, index);
	clear(dat);
	free(dat.pids);
	execve(cmd, args, dat.envp);
	perror(cmd);
	free(cmd);
	free_arr(args);
	exit(1);
}
