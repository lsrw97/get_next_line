/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/01/17 19:52:12 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// what line to read
// where to read from - fd
//

// Hello World!/nMy name is 42/nI love Burgers!/0
// BUFFER_SIZE = 5;

// Hello World!/nMy
//

// check if it has a /n character in string
// if ture -> trunc temp

//
#define BUFFER_SIZE 5

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return(++i);
		i++;
	}
	return (i);
}

void	strcopy(char *str1, char *str2)
{
	int i;

	i = -1;
	while(++i < ft_strlen(str2))
	{
		str1[i] = str2[i];
	}
}

int getIndex(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (i);
}

int	buffereol(char *buffer)
{
	int	i;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			buffer = "My";
			return (1);
	}
	return (0);
}

int	checkeol(char *buffer, char *line)
{
	char *temp;
	int i;
	int j;

	i = -1;
	printf("Index: %d\n", getIndex(buffer));
	temp = malloc(ft_strlen(line) + ft_strlen(buffer));
	j = ft_strlen(line);
	strcopy(temp, line);
	while (buffer[++i] != '\0')
	{
		if (buffer[i] != '\0' && buffer[i] != '\n')
			{temp[j++] = buffer[i];
					// printf("\ntemp:%s\n", temp);
}
		else
		{
			if (buffer[i] == '\n')
				{
					temp[j] == '\n';
					free(line);
					line = malloc(ft_strlen(temp));
					strcopy(line, temp);
					printf("\nline: %s\n", line);
					return (1);
				}
			if (buffer[i] == '\0')
				{
				return (2);
				}

		}

	}
	free(line);
	line = malloc(ft_strlen(temp));
	strcopy(line, temp);
	return (0);
}

char	*get_next_line(int fd)
{
	char *temp1;
	char *temp2;
	static int linesize;
	int bufsize = 5;
	int i;
	char *line;
	static char *buffer;

	if (!buffer)
		buffer = malloc(read(fd, buffer, BUFFER_SIZE) + 1);
		line = malloc(ft_strlen(buffer));
		read(fd, buffer, BUFFER_SIZE);
	buffer[ft_strlen(buffer)] = '\0';
	while (!checkeol(buffer, line))
	{
		printf("\nBuffer: %s\n", buffer);
		if(buffereol(buffer))
			read(fd, buffer, BUFFER_SIZE);
		// printf("%s", line);
		// printf("\nline: %s\n", line);
	}
	return (line);
}

int main (void)
{
	static char buffer[BUFFER_SIZE];
	int	fds;

	fds = open("test.txt", O_RDONLY);
	get_next_line(fds);
	get_next_line(fds);

	// printf("%d", fds);
		// get_next_line(fds);

	// get_next_line(fds);
	// get_next_line(fds);
}
