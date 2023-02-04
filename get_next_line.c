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

#define BUFFER_SIZE 1

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		{
			// printf("index: %d, address: %p, c: %d\n\n", i, s, s[i]);
			i++;
		}
	
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
	// printf("src: %s\n", src);
	while (src[++i]){
		dst[i] = src[i];
		}
	// printf("\nstrcopy:  tempsize = %d\n", i + 1);
	dst[i] = '\0';
	// printf("%s", dst)
	// printf("\ntempa: %p\n", dst);
	return (i);
}

void	concatbuffertemp(char *buffer, char *temp, int id)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(temp);
	// printf("\nconcatbuffertemp: tempsize = %d\n", i);

	while (++j <= id)
	{
		// printf("\nconcatbuffertemp: tempsize = %d, buffer[j]: %d\n", i, buffer[j]);

		temp[i++] = buffer[j];

	}
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
	// printf("buffer: %s, buffer[0]: %d, buffer[1]: %d, buffer[2]: %d\n\n", buffer, buffer[0], buffer[1], buffer[2]);
	// printf("buffern: %d\nBuffer: %s\n", ft_strlen(buffer), buffer);
	temp = (char *)malloc(size + 1);


	temp[0] = 0;

	if (ft_strlen(line))
		strcopy(temp, line);

	// printf("\nline: %d\n", line[1]);
	// printf("line: %s, line[0]: %d, line[1]: %d, line[2]: %d, line[3]: %d, line[4]: %d\n", line, line[0], line[1], line[2], line[3], line[4]);

	id = getId(buffer, state);
			// printf("\naddBufferStringToLine: %d, temp: %d (with terminator)\n", state, size + 1);
			// printf("temp: %s\n", temp);

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
	// printf("%s", buffer);
	while (buffer[i] != '\n')
		i++;
	while(buffer[++i])
		{
			// printf("\nBuffer: %s, i: %d, j: %d, buffer[%d]\n", buffer, i, j, buffer[i]);
			buffer[j] = buffer[i];
			j++;
			
		}
		// printf("j: %d\n", j);
	buffer[j] = '\0';
	// printf("buffer: %s\n", buffer);
	// printf("buffer1: %d\n", j);
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
	{
		size = read(fd, buffer, BUFFER_SIZE);
	}
	if (!buffer)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, buffer, BUFFER_SIZE);
	}
		

	// printf("%d", size);
	if (!size)
	{
		return (NULL);
	}
		
	while (size < BUFFER_SIZE)
		buffer[size++] = '\0';
	buffer[BUFFER_SIZE] = '\0';
	// line = (char *)malloc(ft_strlen(buffer) + 1);
	line = NULL;
	// printf("line address: %p\n", line);
	// printf("buffer[i]: %p\n", buffer);
	while(1)
	{
		// printf("%d\n", i);
		if(buffer[++i] == '\n')
		{
			temp = addBufferStringToLine(buffer, line, 10);
			// printf("%zu\n", ft_strlen(temp));
			if(line)
				free(line);
			line = (char *)malloc(ft_strlen(temp) + 1);
			// printf("\nbuffer: n: line: %d (with terminator)\n", ft_strlen(temp) + 1);
			strcopy(line, temp);
			// printf("\ntemp: %s, line[0]: %d, line[1]: %d, line[2]: %d, line[3]: %d, line[4]: %d\n", temp, line[0], line[1], line[2], line[3], line[4]);
			free(temp);
			convertBuffer(buffer);
			break;
		}
		else if(buffer[i] == '\0')
		{
			temp = addBufferStringToLine(buffer, line, 0);
			// printf("temp: %s\n", temp);
			if(line)
				free(line);
			line = (char *)malloc(ft_strlen(temp) + 1);
			// printf("\nbuffer: 0: line: %d (with terminator)\n", ft_strlen(temp) + 1);
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
