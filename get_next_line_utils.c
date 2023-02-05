/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:12:53 by eelisaro          #+#    #+#             */
/*   Updated: 2023/02/05 19:35:21 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] && s[i] != '\n')
			i++;
	return (i + (s[i] == '\n'));
}
int	strcopy(char *dst, char *src, int index, char c)
{
	int i;

	i = 0;
	if(!src)
		return (0);
	if(dst)
		while (src[i] != c)
			dst[index++] = src[i++];
	if (c == '\n')
		dst[index++] = '\n';
	dst[index] = '\0';
	return (index);
}

char *addBufferToString(char *line, char *buffer, int c, int index)
{
	char *temp;
	int size;
	int i;

	i = 0;
	size = 0;
	temp = line;
	line = (char *)malloc(ft_strlen(temp) + ft_strlen(buffer) + 1);
	size = strcopy(line, temp, 0, 0);
	strcopy(line, buffer, size, c);
	if (c == '\n')
	{
		while(buffer[index])
			buffer[i++] = buffer[++index];
		buffer[i] = 0;
	}
	else
	{
		while(i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
	if(temp)
		free(temp);
	return (line);
}