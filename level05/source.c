
void main(void)
{
	char	buff[100];
	int		i;
	int		len;

	len = fgets(buff,100,0);
	while (i < len)
	{
		if ('@' < buff[i]  && buff[i] > '[')
			buff[i] -= 32;
		++i;
	}
	printf(buff);
	exit(0);
	return 0;
}
