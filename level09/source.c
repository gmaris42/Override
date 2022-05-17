void	secret_backdoor(void)
{
	char cmd[128];
	
	fgets(cmd, 128,stdin);
	system(cmd);
	return;
}

void	set_msg(char *buffer)
{
	long	i;
	char	*tmp;
	char	msg[128];
	
	tmp = msg;
	for (i = 128; i != 0; i--) {
		*tmp = 0;
		tmp = tmp + 1;
	}
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(msg, 1024, stdin);
	strncpy(buffer, msg, 180);
	return;
}

void	set_username(char *buffer)
{
	long	i;
	char	*puVar2;
	char	username[17];
	int		j;
	
	tmp = username;
	for (i = 16; i != 0; i--) {
		*tmp = 0;
		++tmp;
	}
	puts(">: Enter your username");
	printf(">>: ");
	fgets(username, 128, stdin);
	for (j = 0; j < 41 && username[j] != '\0'; j++) {
		buffer[140 + j] = username[j];
	}
	printf(">: Welcome, %s", buffer + 140);
	return;
}

void	handle_msg(void)
{
	char	buffer[140];
	char	*local_3c;
	char	*local_34;
	char	*local_2c;
	char	*local_24;
	char	*local_1c;
	int		local_14;
	
	local_3c = 0;
	local_34 = 0;
	local_2c = 0;
	local_24 = 0;
	local_1c = 0;
	local_14 = 140;
	set_username(buffer);
	set_msg(buffer);
	puts(">: Msg sent!");
	return;
}

int 	main(void)
{
	puts(
		"--------------------------------------------\n|	 ~Welcome to l33t-m$n ~		v1337				|\n- -------------------------------------------"
		);
	handle_msg();
	return 0;
}
