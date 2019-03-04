#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"

int main()
{
	int fd;
	int i;
	int nb = 0;
	char *str;
	char *str2;

	for (i = 0; i < 4097; i++)
	{
		str = ft_itoa(i);
		str2 = ft_strjoin(str, "}\n");
		fd = open("headers/malloc.h", O_RDWR);
		lseek(fd, 1500, SEEK_SET);
		write(fd, str2, strlen(str2));
		free(str);
		free(str2);
		close(fd);
	}
	return (0);
}