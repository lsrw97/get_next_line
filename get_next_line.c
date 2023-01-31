/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/01/27 20:09:25 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// // what line to read
// // where to read from - fd
// //

// // Hello World!/nMy name is 42/nI love Burgers!/0

// // Hello World!/nMy
// //

// // check if it has a /n character in string
// // if ture -> trunc temp

// //
// #define BUFFER_SIZE 5



// void	strcopy(char *str1, char *str2)
// {
// 	int i;

// 	i = -1;
// 	while(++i < ft_strlen(str2))
// 	{
// 		str1[i] = str2[i];
// 	}
// }

// int getIndex(char *buffer)
// {
// 	int	i;

// 	i = -1;
// 	while (buffer[++i])
// 	{
// 		if (buffer[i] == '\n')
// 			return (i);
// 	}
// 	return (i);
// }

// int	buffereol(char *buffer)
// {
// 	int	i;
// 	int j;

// 	j = 0;
// 	i = -1;
// 	while (buffer[++i])
// 	{
// 		// printf("Bufferol: %s\n\n", buffer);
// 		if (buffer[i] == '\n')
// 		{
// 			while (buffer[++i])
// 				buffer[j++] = buffer[i];
// 			// printf("MyBuffer: %s", buffer);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

// int	checkeol(char *buffer, char *line, char *eol)
// {
// 	char *temp;
// 	int i;
// 	int j;
// 	int k;

// 	k = 0;
// 	i = -1;
// 	// printf("Index: %d\n", getIndex(buffer));
// 	temp = malloc(ft_strlen(line) + ft_strlen(buffer));
// 	j = ft_strlen(line);
// 	strcopy(temp, line);
// 	while (buffer[++i])
// 	{
// 		if (buffer[i] != '\0' && buffer[i] != '\n')
// 			{temp[j++] = buffer[i];
// 					// printf("\ntemp:%s\n", temp);
// }
// 		else
// 		{
// 			if (buffer[i] == '\n')
// 				{
// 					buffer[i] = 0;
// 					while (buffer[++i])
// 					{
// 						buffer[k++] = buffer[i];
// 						buffer[i] = '\0';
// 					}
// 					buffer[i] = '\0';
// 					// printf("\nMybuffer: %s\n", buffer);
// 					free(line);
// 					eol[0] = 1;
// 					temp[j] = '\n';
// 					temp[j + 1] = '\0';
// 					line = malloc(ft_strlen(temp));
// 					strcopy(line, temp);
// 					// printf("\nline: %s", line);
// 					return (1);
// 				}
// 		}
// 	}
// 	free(line);
// 	eol[0] = 0;
// 	temp[j] = '\0';
// 	// printf("i was here: %s\n", line);
// 	line = malloc(ft_strlen(temp) + 1);
// 	// printf("%d\n", ft_strlen(temp));
// 	strcopy(line, temp);
// 	line[j] = '\0';
// 	return (0);
// }

// void	fillBuffer(char *str)
// {

// }

// char	*get_next_line(int fd)
// {
// 	char *temp1;
// 	char *temp2;
// 	static int linesize;
// 	int i;
// 	char *line;
// 	static char *buffer;
// 	static char *eol;

// 	eol = malloc(1);
// 	eol[0] = 0;
// 	if (!buffer)
// 	// hello
// 		buffer = malloc(read(fd, buffer, BUFFER_SIZE) + 1);

// 	line = malloc(ft_strlen(buffer));
// 	//	if there isn't a \n in a buffer string
// 	if(!eol[0])
// 	{
// 		if(!read(fd, buffer, BUFFER_SIZE))
// 			return (NULL);
// 	}
// 	buffer[ft_strlen(buffer)] = '\0';
// 	while (!checkeol(buffer, line, eol))
// 	{
// 			if(!read(fd, buffer, BUFFER_SIZE))
// 				break;
// 			// BUFFER = hel__\0 -> hel\0\0\0
// 			buffer[BUFFER_SIZE + 1] = '\0';
// 	}
// 	// printf("eol: %d", eol[0]);
// 	printf("%s", line);

// 	return (line);
// }

#define BUFFER_SIZE 2

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
	// printf("%s", dst);
	return (i);
}

void	concatbuffertemp(char *buffer, char *temp, int id)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(temp);
	while (++j <= id)
	{
		temp[i++] = buffer[j];
	}

	// temp[i] = '\0';

}

char	*addBufferStringToLine(char *buffer, char *line, int state)
{
	int id;
	char *temp;
	int size;

	size = ft_strlen(buffer) + ft_strlen(line);
	printf("buffern: %d\nBuffer: %s\n", ft_strlen(buffer), buffer);
	temp = (char *)malloc(size + 1);
	printf("size: %d\n\n", size);
	temp[size] = '\0';

	if (line)
		strcopy(temp, line);

	id = getId(buffer, state);
	concatbuffertemp(buffer, temp, id);

	return (temp);
	// printf("linemem: %p\n", line);
	// if(line)
	// 	free(line);
	// printf("linemem: %p\n", line);

	// line = malloc(ft_strlen(temp) + 1);
	// printf("linemem: %p\n", line);
	// line[ft_strlen(temp)] = '\0';
	// strcopy(line, temp);
	// printf("Line copied: %s\n%p", line, line);
}

void	convertBuffer(char *buffer)
{
	int i;
	int j;

	j = 0;
	i = 0;
	// printf("%s", buffer);
	while (buffer[i] != '\n')
		i++;
	while(buffer[++i])
		{
			// printf("\nBuffer: %s, i: %d, j: %d, buffer[%d]\n", buffer, i, j, buffer[i]);
			buffer[j] = buffer[i];
			j++;
		}
	buffer[j] = '\0';
	// printf("buffer1: %d\n", j);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	static char *line;
	int i;
	int size;
	char *temp;

	i = -1;
	if (!buffer || !ft_strlen(buffer))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	// printf("%d", size);
	if (!size)
		return (NULL);
	while (size < BUFFER_SIZE)
		buffer[size++] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	if (line)
		free(line);
	line = (char *)malloc(ft_strlen(buffer) + 1);
	line[0] = 0;
	line[1] = 0;
	line[2] = 0;

	while(1)
	{
		// printf("%d\n", i);
		if(buffer[++i] == '\n')
		{
			temp = addBufferStringToLine(buffer, line, 10);
			printf("%zu\n", ft_strlen(temp));
			if(line)
				free(line);
			line = malloc(ft_strlen(temp) + 1);
			strcopy(line, temp);
			free(temp);
			convertBuffer(buffer);
			i = -1;
			break;
		}
		else if(buffer[i] == '\0')
		{
			temp = addBufferStringToLine(buffer, line, 0);
			if(line)
				free(line);
			line = malloc(ft_strlen(temp) + 1);
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
	printf("Line: %s", line);
	return (line);
}



int main (void)
{
	int	fds;

	fds = open("test.txt", O_RDONLY);

	get_next_line(fds);
	get_next_line(fds);
	get_next_line(fds);
}
