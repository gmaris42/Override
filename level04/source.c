int main(void)
{
	char buff[32];
	pid_t pid;
	int ret;
	int child_ret;

	pid = fork();
	b_zero(buff, 32);
	
	if (pid == 0) {
		prctl(1,1);
		ptrace(0,0,0,0);
		puts("Give me some shellcode, k");
		gets(buff);
	}
	else {
		while (ptrace(3, pid, 44, 0) != 11)
		{
			wait(&child_ret);
			if (child_ret == 127)
			{
				puts("child is exiting ...");
				return 0
			}
		}
		puts("no exec() for you");
		kill(pid,9);
	}
	return 0;
}
