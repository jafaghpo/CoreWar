#include <fcntl.h>

int main()
{
	int		fd;
	char	ouais[5];
	char	str1[300] = "(../resources/corewar 2017/adenis/Explosive_Kitty.cor -d ";
	char	str2[] = " | cut -c 9-200 | tail -n 64 > leleur && ./corewar 2017/adenis/Explosive_Kitty.cor -d ";
	char	str3[] = " > lenotre && diff leleur lenotre && echo ";
	char	str4[] = ")\n";
	int		size = strlen(str1);

	fd = open("SUPER", O_WRONLY);
	int i = 0;
	while (i < 9999)
	{
		sprintf(ouais, "%.4d", i);
		strcat(str1, ouais);
		strcat(str1, str2);
		strcat(str1, ouais);
		strcat(str1, str3);
		strcat(str1, ouais);
		strcat(str1, str4);
		write(fd, str1, strlen(str1));
		str1[size] = 0;
		i++;
	}
}
