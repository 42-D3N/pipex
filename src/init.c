/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:53:25 by tle-pape          #+#    #+#             */
/*   Updated: 2025/01/31 10:25:25 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*here_doc_handle(char *limiter, t_pipex dat)
{
	int		tmp;
	char	*nl;

	tmp = open(".tmp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tmp < 0)
	{
		close(dat.outfile);
		handle_error("Error with creation of tmp file for here_doc", dat, 1);
	}
	ft_putstr_fd("pipe heredoc> ", 1);
	limiter = ft_strjoin(limiter, "\n");
	nl = get_next_line(0);
	while (ft_strncmp(limiter, nl, ft_strlen(limiter) + 1) != 0)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		ft_putstr_fd(nl, tmp);
		free(nl);
		nl = get_next_line(0);
	}
	free(limiter);
	free(nl);
	close(tmp);
	return (".tmp.txt");
}

int	open_file(char *path, int out, t_pipex dat)
{
	int	fd;

	fd = -99;
	if (out == 1)
	{
		if (access(path, F_OK) == -1)
			fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (access(path, W_OK) == -1)
			handle_error("Error with outfile permissions", dat, 1);
		else
			fd = open(path, O_WRONLY);
	}
	else if (access(path, F_OK | R_OK) == -1)
		handle_error("Error with Infile permissions / existence", dat, 0);
	else
		fd = open(path, O_RDONLY);
	return (fd);
}
