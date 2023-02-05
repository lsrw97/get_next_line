#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t	ft_strlen(const char *s);
int 	getId(char *buffer, char c);
int	    strcopy(char *dst, char *src, int index, char c);

void	concatbuffertemp(char *buffer, char *temp, int id);
void	convertBuffer(char *buffer);
char *addBufferToString(char *line, char *buffer, int c, int index);
char	*get_next_line(int fd);

#endif
