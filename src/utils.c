/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:21:59 by tle-pape          #+#    #+#             */
/*   Updated: 2025/01/31 10:53:45 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	handle_error(char *error, t_pipex dat, int clear_dat)
{
	perror(error);
	if (clear_dat == 1)
		exit(1);
	else if (clear_dat == 2)
	{
		free(dat.pids);
		clear(dat);
		exit(1);
	}
	else if (clear_dat == 127)
	{
		free(dat.pids);
		clear(dat);
		exit(127);
	}
}

void	free_arr(char **s)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (s[max])
		max++;
	while (i < max)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	clear(t_pipex dat)
{
	int	i;

	i = 0;
	if (dat.cmds)
		free(dat.cmds);
	close(dat.outfile);
	if (dat.infile >= 0)
		close(dat.infile);
	while (i < (dat.cmd_index_max - 1) * 2)
	{
		close(dat.pipe[i]);
		i++;
	}
	free(dat.pipe);
}

char	*get_full_path(char **cmd_path, char *cmd)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (cmd_path[i])
	{
		tmp = ft_strjoin(cmd_path[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_arr(cmd_path);
			return (path);
		}
		free(path);
		i++;
	}
	free_arr(cmd_path);
	return (NULL);
}

char	*handle_path(char **envp, char *cmd)
{
	int		i;
	char	**cmd_path;

	i = 0;
	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/') != NULL)
	{
		if (access(cmd, F_OK))
			return (NULL);
		else
			return (cmd);
	}
	while (ft_strncmp("PATH=", envp[i], 5) && envp[i])
		i++;
	if (!envp[i])
		return (NULL);
	envp[i] += 5;
	cmd_path = ft_split(envp[i], ':');
	cmd = get_full_path(cmd_path, cmd);
	return (cmd);
}
