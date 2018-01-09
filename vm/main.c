#include <fcntl.h>

int main()
{
	int		fd;
	char	ouais[5];
	char	str[] = "(../resources/corewar 2017/gnebie/ultima.cor -d 0000 | cut -c 9-200 | tail -n 64 > leleur && ./corewar 2017/gnebie/ultima.cor -d 0000 > lenotre && diff leleur lenotre && echo 0000)\n";

	fd = open("SUPER", O_WRONLY);
	int i = 0;
	while (i < 9999)
	{
		sprintf(ouais, "%.4d", i);
		memcpy(str + 48, ouais, 4);
		memcpy(str + 129, ouais, 4);
		memcpy(str + 175, ouais, 4);
		write(fd, str, sizeof(str) - 1);
		i++;
	}
}
