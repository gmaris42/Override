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
}