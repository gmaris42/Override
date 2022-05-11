<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void clear_stdin(void) {
    char value = 0;

    while (value != 255) {
        value = getchar();
        if (value == 10)
            return;
    }
}

int get_unum(void) {
    int input = 0;

    fflush(stdout);
    scanf("%u", &input);
    clear_stdin();
    return input;
}

void prog_timeout() {
    exit(1);
}

void decrypt(int rot) {
    char buffer[] = "Q}|u`sfg~sf{}|a3";
    size_t len;

    len = strlen(buffer);
    for (size_t i = 0; i++; i < len) {
        buffer[i] = buffer[i] ^ rot;
    }

    if (!strncmp(buffer, "Congratulations!", 17)) {
        system("/bin/sh");
        return;
    } 
    puts("\nInvalid Password");
}

void test(int input, int password) {
    int diff = password - input;

    switch (diff)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        decrypt(diff);
        break;
    default:
        decrypt(rand());
        break;
    }
}

int main(int argc, char *argv[]) {
    int password;

    srand(time(0));
    puts("\b***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("\b***********************************");

    printf("Password:");
    scanf("%d", &password);
    test(password, 0x1337d00d); // 322424845
=======
int main(void)
{
	int val;
	srand(time(0));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");
	printf("Password:");
	scanf("%d", val);
	test(val, 322424845);
	return 0;
}
void test(int val,int nb)
{
	int uVar1;
	
	val = nb - val;

	switch(val) {
	default:
		decrypt(rand());
		break;
	case 1:
		decrypt(val);
		break;
	case 2:
		decrypt(val);
		break;
	case 3:
		decrypt(val);
		break;
	case 4:
		decrypt(val);
		break;
	case 5:
		decrypt(val);
		break;
	case 6:
		decrypt(val);
		break;
	case 7:
		decrypt(val);
		break;
	case 8:
		decrypt(val);
		break;
	case 9:
		decrypt(val);
		break;
	case 16:
		decrypt(val);
		break;
	case 17:
		decrypt(val);
		break;
	case 18:
		decrypt(val);
		break;
	case 19:
		decrypt(val);
		break;
	case 20:
		decrypt(val);
		break;
	case 21:
		decrypt(val);
	}
	return;
}

void decrypt(int param_1)
{
	char	str_crypt[17] = "Q}|u`sfg~sf{}|a3";

	int i = 0;
	int len = 17;
	while(i < 17)
	{
		str_crypt[i] = param_1 ^ str_crypt[i] ;
		++i;
	}
	if (strcmp(str_crypt, "Congratulations!") == 0)
		system("/bin/sh");
	else
		puts("\nInvalid Password");
>>>>>>> 655bebc034947e79de8b9192b7aa3c1fd12dbeb8
}