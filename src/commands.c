/* This file is responsible for all the supported commands within my shell */

// Clear Terminal //
int clr()
{
    char *command[2];
    command[0] = "clear";
    command[1] = NULL;

    pid_t pid = fork();
    if (pid == 0)
    {
        execvp("clear", command);
    }
    wait(NULL);
}


// Quit command to exit shell //
int quit()
{
    exit(0);
}
