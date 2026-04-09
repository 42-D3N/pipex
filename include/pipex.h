/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 08:47:15 by tle-pape          #+#    #+#             */
/*   Updated: 2025/01/23 16:22:03 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		cmd_index_max;
	int		*pipe;
	int		*pids;
	char	**cmds;
	char	**envp;
}				t_pipex;

int			open_file(char *path, int out, t_pipex dat);
char		*here_doc_handle(char *limiter, t_pipex dat);
char		*handle_path(char **envp, char *cmd);
void		handle_error(char *error, t_pipex dat, int clear);
void		clear(t_pipex dat);
void		free_arr(char **s);
void		forking(t_pipex dat, int index);
t_pipex		pipe_init(t_pipex dat);

#endif
