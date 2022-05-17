We get the binary out of the Vm using this cmd:

`scp -P 4242 level06@192.168.56.103:./level06 .binary/level06`

By rewriting in c, we see your login input is hashed by foncion auth.\
Then our serial is compared to the hash and if they are the same we get a shell.

We did a small program that do the same hash but print it, the login mustn't have `space` in it : 
```c
#include <stdio.h>
#include <string.h>
int auth(char *login)

{
	int				len;
	int				iVar3;
	int				i;
	unsigned int	local_14;
	
	len = strcspn(login, "\n");
	login[len] = 0;
	len = strnlen(login, 150);
	if (len < 6)
		return 1;
	local_14 = (login[3] ^ 4919) + 0x5eeded;
	i = 0;
	while (i < len)
	{
		if (login[i] < ' ')
			return 1;
		local_14 = local_14 + (login[i] ^ local_14) % 1337;
		++i;
	}
	return local_14;
}


int main(int argc, char **argv)
{
	char buff[150];

	puts("login:");
	scanf("%s", buff);

	printf("\n For login = [%s]\n\tSerial is [%u]\n", buff, auth(buff));
}
```

With it we find that login `hello42` get serial `6233701`

```s
**********************************
*               level06           *
***********************************
-> Enter Login: hello42
***********************************
***** NEW ACCOUNT DETECTED ********
***********************************
-> Enter Serial: 6233701
Authenticated!
$ cat /home/users/level07/.pass
GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8
```
