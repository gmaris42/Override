We get the binary out of the Vm using this cmd:

`scp -P 4242 level3@192.168.56.103:./level3 .binary/level3`

Rewrite in c

We find we need to input a number\
in test we can see the `322424845 - input` must respect (`nb > 0 && nb < 10` || `nb > 15 && nb < 22`

and the number must transform ```Q}|u`sfg~sf{}|a3``` into ```Congratulations!```\
via this
```c
	char	str_crypt[17] = "Q}|u`sfg~sf{}|a3";

	int i = 0;
	int len = 17;
	while(i < 17)
	{
		str_crypt[i] = param_1 ^ str_crypt[i] ;
		++i;
	}
```

Let's find the needed input by trying with this :
```c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int nb = 322424845;
	int val = atoi(argv[1]);

	char srt[17] = "Q}|u`sfg~sf{}|a3";
	int i = 0;
	while (i < 17)
	{
		printf("%d^%c = [%c]\n", val, srt[i], val^srt[i]);
		++i;
	}
	return 0;
}
```


18^'Q' => 'C' and so on so the password is `322424845 - input` = 18\
password is `322424827`

```
level03@OverRide:~$ ./level03 
***********************************
*               level03         **
***********************************
Password:322424827
$ cat /home/users/level04/.pass
kgv3tkEb9h2mLkRsPkXRfc2mHbjMxQzvb2FrgKkf
```