undefined8 main(void)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  char password[14];
  char *target [6];
  char username[12];
  int ret;
  long fd;
  
  fd = 0;
  ret = 0;
  fd = fopen("/home/users/level03/.pass", "r", "r");
  if (fd == 0)
  {
    fwrite("ERROR: failed to open password file\n",1,36,2);
    exit(1);
  }
  ret = fread(target,1,41, local_10);
  if (ret != 41)
  {
    fwrite("ERROR: failed to read password file\n",1,36,2);
    fwrite("ERROR: failed to read password file\n",1,36,2);
    exit(1);
  }
  fclose(local_10);
  puts("===== [ Secure Access System v1.0 ] =====");
  puts("/***************************************\\");
  puts("| You must login to access this system. |");
  puts("\\**************************************/");
  printf("--[ Username: ");
  fgets(username,100,0);
  printf("--[ Password: ");
  fgets(password,100,0);
  puts("*****************************************");
  if (strncmp(target, password, 41) == 0)
  {
    printf("Greetings, %s!\n", username);
    system("/bin/sh");
    return 0;
  }
  printf(username);
  puts(" does not have access!");
  exit(1);
}