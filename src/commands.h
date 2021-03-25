/* This file is responsible for all the supported commands within my shell */

// Clear Terminal //
int clr()
{
    char *command[2];
    command[0] = "clear";
    command[1] = NULL;

    pid_t pid = fork(); // this fork() command returns twice, if the process fails it returns -1 //
    if (pid == 0) // if the fork process succeeds then it returns a 0 to the child, therefore I will be using the fork method for checking if a process has failed or not. //
    {
        execvp("clear", command); // I use execvp here as the child process does not need to run the same program as the parent. //
    }
    wait(NULL);
}


// Quit command to exit shell //
int quit()
{
    exit(0);
}

// Lists of directories //
int dir()
{
    char cwd[200]; //current working directory //.
    char *command[3];

    command[0] = "ls";
    command[1] = NULL;

    pid_t pid = fork();
    if (pid == 0)
    {
        execvp("ls", command);
    }
    wait(NULL);
}


// changes current directory //
int changedir(char *args[])
{
    char cwd[200];
    getcwd(cwd, sizeof(cwd));

    if(args[1] == NULL)
    {
        printf("%s\n", cwd);
    }
    else
    {
        chdir(args[1]);
        getcwd(cwd, sizeof(cwd));
        setenv("PWD", cwd, 1);
        printf("%s\n", cwd);
    }
}


// environ, taken from lab 4C //
int enviroment(){

    extern char **environ;
    for (int i = 0; environ[i] !=NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
    
    printf("\n");
    
}


// echo -  prints the argument //
int echo(char *args[])
{
    for (int i = 1; args[i]; i++)
    {
        printf("%s ", args[i]);
    }
    printf("\n");
    
}
