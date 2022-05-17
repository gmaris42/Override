void log_wrapper(FILE *log_fd,char *str,char *param)
{
	char cVar1;
	size_t i;
	ulong i;
	long in_FS_OFFSET;
	char dest[264];
	long local_10;
	
	local_10 = *(long *)(in_FS_OFFSET + 0x28);
	strcpy(dest, str);
	snprintf(dest + strlen(local_188), 254 - strlen(local_188), param);
	i = strcspn(dest, "\n");
	dest[i] = '\0';
	fprintf(log_fd, "LOG: %s\n", dest);
	if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
		__stack_chk_fail();
	}
	return ;
}

int main(int ac, char **av)
{
	int			fd;
	int			ret;
	FILE		*log_fd;
	FILE		*stream;
	ulong		len;
	char		*tmp;
	char		c;
	char		*path;
	long int	in_FS_OFFSET;
	long int	local_10;
	
	local_10 = *(long *)(in_FS_OFFSET + 0x28);
	if (ac != 2) {
		printf("Usage: %s filename\n", *av);
	}
	log_fd = fopen("./backups/.log", "w");
	if (!log_fd) {
		printf("ERROR: Failed to open %s\n","./backups/.log");
		exit(1);
	}
	log_wrapper(log_fd, "Starting back up: ", av[1]);
	stream = fopen(av[1], "r");
	if (!stream) {
		printf("ERROR: Failed to open %s\n", av[1]);
		exit(1);
	}
	path = "./backups/";
	len = strlen(path);
	strncat(path, av[1], 99 - len);
	fd = open(path, 193, 432);
	if (fd < 0) {
		printf("ERROR: Failed to open %s%s\n","./backups/", av[1]);
		exit(1);
	}
	c = -1;
	while(true) {
		ret = fgetc(stream);
		c = (char)ret;
		if (c == -1) break;
		write(fd, &c, 1);
	}
	log_wrapper(log_fd, "Finished back up ", av[1]);
	fclose(stream);
	close(fd);
	if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
		__stack_chk_fail();
	}
	return 0;
}

