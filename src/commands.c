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
