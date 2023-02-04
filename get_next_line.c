/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/01/31 15:23:48 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 42

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
			i++;	
	return (i);
}

int getId(char *buffer, char c)
{
	int i;

	i = 0;
	while (buffer[i] != c)
		i++;
	return (i);
}

int	strcopy(char *dst, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (i);
}

void	concatbuffertemp(char *buffer, char *temp, int id)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(temp);
	while (++j <= id)
		temp[i++] = buffer[j];
	if(temp[i - 1])
		temp[i] = '\0';

}

char	*addBufferStringToLine(char *buffer, char *line, int state)
{
	int id;
	char *temp;
	int size;

	size = ft_strlen(buffer);
	if(line)
		size += ft_strlen(line);
	temp = (char *)malloc(size + 1);
	temp[0] = 0;
	if (ft_strlen(line))
		strcopy(temp, line);
	id = getId(buffer, state);
	concatbuffertemp(buffer, temp, id);
	temp[size] = '\0';
	return (temp);
}

void	convertBuffer(char *buffer)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (buffer[i] != '\n')
		i++;
	while(buffer[++i])
		{
			buffer[j] = buffer[i];
			j++;
		}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char *line;
	int i;
	int size;
	char *temp;

	i = -1;
	if(!ft_strlen(buffer))
		size = read(fd, buffer, BUFFER_SIZE);
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (!size)
		return (NULL);		
	while (size < BUFFER_SIZE)
		buffer[size++] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	line = NULL;
	while(1)
	{
		if(buffer[++i] == '\n')
		{
			temp = addBufferStringToLine(buffer, line, 10);
			if(line)
				free(line);
			line = (char *)malloc(ft_strlen(temp) + 1);
			strcopy(line, temp);
			free(temp);
			convertBuffer(buffer);
			break;
		}
		else if(buffer[i] == '\0')
		{
			temp = addBufferStringToLine(buffer, line, 0);
			if(line)
				free(line);
			line = (char *)malloc(ft_strlen(temp) + 1);
			strcopy(line, temp);
			line[ft_strlen(temp)] = '\0';
			free(temp);
			size = read(fd, buffer, BUFFER_SIZE);
				if (size)
				{
					while (size <= BUFFER_SIZE)
						buffer[size++] = '\0';
					i = -1;
					continue;
				}
				buffer[0] = '\0';
				break;
		}
	}
	return (line);
}

int main (void)
{
	int	fds;

	fds = open("test.txt", O_RDONLY);
	// fds = 0;
	char *str;

	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
	str = get_next_line(fds);
	printf("%s", str);
	free(str);
}
