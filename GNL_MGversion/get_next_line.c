#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int			byte_read;
	static char	buff[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	byte_read = 1;
	while (1)
	{
		if (!buff[0])
			byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read > 0)
			line = ft_get_line(buff, line);
		if (ft_checknl(buff) || byte_read < 1)
			break ;
	}
	return (line);
}

// int main (void)
// {
// 	int	fds;

// 	fds = open("read", O_RDONLY);
// 	// fds = 0;
// 	char *str;

// 	while(1)
// 	{
// 		str = get_next_line(fds);
// 		if (!str)
// 			break;
// 		printf("%s", str);
// 		free(str);
// 	}
// }
