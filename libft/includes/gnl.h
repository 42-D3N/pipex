/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-pape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:51:28 by tle-pape          #+#    #+#             */
/*   Updated: 2024/11/18 10:22:11 by tle-pape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);

#endif
