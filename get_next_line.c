/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsrw97 <lsrw97@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 07:10:54 by lsrw97            #+#    #+#             */
/*   Updated: 2023/01/10 17:22:14 by lsrw97           ###   ########.fr       */
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

char *readOneLine(int fd, int line)
{
	char *str;

}

char *get_next_line(int fd)
{
	char *str;
	str = malloc(1000);
	read(fd, str, 500);
	if(!strcmp(str, ""))
		printf("NULL");
	printf("%s", str);

	// read the first line till \n
	// count the characters and allcoate memory to string
	//

	return str;
}

void	goToLine(int i, int fd)
{

}

int main (void)
{
	int fds = open("test.txt", O_RDONLY);
	get_next_line(fds);
	// get_next_line(fds);
	// get_next_line(fds);
}
