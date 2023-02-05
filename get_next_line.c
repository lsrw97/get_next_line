/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/02/05 22:28:45 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cleanbuffer(char *buffer)
{
	int	i;

	i = -1;
	while(++i <= BUFFER_SIZE)
		buffer[i] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			size;

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buffer[0])
		if (!read(fd, buffer, BUFFER_SIZE))
			return (NULL);
	line = NULL;
	i = -1;
	while (++i >= 0)
	{
		if (!buffer[i] || buffer[i] == '\n')
		{
			size = buffer[i];
			// printf("buffer1: %s, buffersize= %d\n", buffer, ft_strlen(buffer));
			line = addbuffertostring(line, buffer, buffer[i], i);
			// printf("buffer2: %s, buffersize= %d\n", buffer, ft_strlen(buffer));
			if (!buffer[0])
			{
				cleanbuffer(buffer);
				if (size)
					break ;
				size = read(fd, buffer, BUFFER_SIZE);
				if (!size)
					break ;
				i = -1;
				continue ;
			}
			break ;
		}
	}
	return (line);
}

int main (void)
{
	int	fds;

	fds = open(0, O_RDONLY);
	char *str;

	// while(1)						
	// {
	// 	str = get_next_line(fds);
	// 	if (!str)
	// 		break;
	// 	printf("Line: %s", str);
	// 	free(str);
	// }

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