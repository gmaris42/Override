int auth(char *login, unsigned int serial)

{
	int				len;
	int				iVar3;
	int				i;
	unsigned int	local_14;
	
	len = strcspn(login, "\n");
	login[len] = 0;
	len = strnlen(login);
	if (len < 6)
		return 1;
	iVar3 = ptrace();
	if (iVar3 == -1) {
		puts(" ");
		puts("| !! TAMPERING DETECTED !!  |");
		puts(" ");
		return 1;
	}
	local_14 = (login[3] ^ 4919) + 0x5eeded;
	i = 0;
	while (i < len)
	{
		if (login[i] < ' ')
			return 1;
		local_14 = local_14 + (login[i] ^ local_14) % 1337;
		++i;
	}
	if (serial == local_14)
		return 0;
	return 1;
}

int main(void)
{
  int iVar1;
  int iVar2;

  puts("*********************************");
  puts("               level06           ");
  puts("*********************************");
  printf("-> Enter Login:");
  fgets(iVar1);
  puts("**");
  puts("** NEW ACCOUNT DETECTED **");
  puts("***");
  printf("-> Enter Serial:");
  scanf("%d", iVar2);
  iVar2 = auth(iVar1, iVar2);
  if (iVar2 == 0) {
    puts("Authenticated!");
    system("/bin/sh");
  }
  return iVar2 != 0;
}