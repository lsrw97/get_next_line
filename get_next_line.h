/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:41:35 by eelisaro          #+#    #+#             */
/*   Updated: 2023/03/07 17:38:16 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *s);
int		strcopy(char *dst, char *src, int index, char c);
char	*addbuffertostring(char *line, char *buffer, int c, int index);
char	*get_next_line(int fd);
char	*write_line(char *buffer, char *line, int fd, int i);
void	cleanbuffer(char *buffer);

#endif
