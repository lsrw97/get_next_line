/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelisaro <eelisaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/03/07 17:23:17 by eelisaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || fd > 1024 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
	{
		cleanbuffer(buffer);
		return (NULL);
	}
	if (!buffer[0])
		if (!read(fd, buffer, BUFFER_SIZE))
			return (NULL);
	line = NULL;
	return (write_line(buffer, line, fd, -1));
}

// int main (void)
// {
// 	int	fds;

// 	fds = open("test.txt", O_RDONLY);
// 	char *str;

// 	while(1)
// 	{
// 		str = get_next_line(fds);
// 		if (!str)
// 			break;
// 		printf("Line: %s", str);
// 		free(str);
// 	}

// 	// str = get_next_line(STDIN_FILENO);
// 	// printf("%d",strcmp(str, "0123456789\n"));
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(STDIN_FILENO);
// 	// printf("%d",strcmp(str, "012345678\n"));
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(STDIN_FILENO);
// 	// printf("%d",strcmp(str, "90123456789\n"));
// 	// printf("%s", str);
// 	// free(str);
// 	// str = get_next_line(STDIN_FILENO);
// 	// printf("%d",strcmp(str, "0123456789\n"));
// 	// printf("%s", str);
// 	// free(str);
// }