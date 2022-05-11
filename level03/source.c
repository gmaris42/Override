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
}