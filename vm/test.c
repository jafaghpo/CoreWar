
union
{
	unsigned char	tab[64];
	long double		a;
}     f;

int main()
{
	memset(f.tab + 1, 0xff, 63);
	f.a = 0;
	for (int i = 0; i < 16; i++)
		printf("%hhx ", f.tab[i]);
}
