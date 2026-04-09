/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:15:55 by tle-pape          #+#    #+#             */
/*   Updated: 2025/01/31 08:52:24 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

t_pipex	init_pipex(t_pipex dat, char **argv, int argc, char **envp)
{
	int		i;

	i = 0;
	dat.infile = -99;
	dat.cmd_index_max = 0;
	dat.envp = envp;
	dat.outfile = open_file(argv[argc - 2], 1, dat);
	if (ft_strncmp(*argv, "here_doc", 9) == 0)
	{
		dat.infile = open_file(here_doc_handle(argv[1], dat), 0, dat);
		argv++;
	}
	else
		dat.infile = open_file(*argv, 0, dat);
	argv++;
	while (argv[dat.cmd_index_max])
		dat.cmd_index_max++;
	dat.cmd_index_max--;
	dat.cmds = ft_calloc(dat.cmd_index_max, sizeof(char *));
	while (++i < dat.cmd_index_max + 1)
		dat.cmds[i - 1] = argv[i - 1];
	return (dat);
}

t_pipex	pipe_and_execute(t_pipex dat)
{
	int	i;

	i = -1;
	if (dat.infile == -99)
		i++;
	dat = pipe_init(dat);
	while (++i < dat.cmd_index_max)
	{
		dat.pids[i] = fork();
		if (dat.pids[i] == -1)
		{
			handle_error("Error when created a fork", dat, 0);
			return (dat);
		}
		if (dat.pids[i] == 0)
			forking(dat, i);
	}
	return (dat);
}

void	wait_process(t_pipex dat)
{
	int	i;

	i = 0;
	while (i < dat.cmd_index_max)
	{
		waitpid(dat.pids[i], NULL, 0);
		i++;
	}
	free(dat.pids);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	dat;

	if (argc < 5)
	{
		ft_putstr_fd("Usage : ./pipex [infile] [cmd] [cmd] [outfile]\n", 2);
		exit(1);
	}
	if (argc < 6 && ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		ft_putstr_fd("Usage (here_doc) : ./pipex here_doc [LIMITER] ", 2);
		ft_putstr_fd("[cmd] [cmd] [outfile]\n", 2);
		exit(1);
	}
	dat = init_pipex(dat, argv + 1, argc, envp);
	dat.pids = ft_calloc(sizeof(int), dat.cmd_index_max);
	dat = pipe_and_execute(dat);
	clear(dat);
	if (access(".tmp.txt", F_OK) != -1)
		unlink(".tmp.txt");
	wait_process(dat);
	exit(0);
}
