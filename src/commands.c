/* Name: Imrich Toth */
/* Student number: 19307456 */
/* I acknowledge the DCU integrity policy, this code was fully written by myself */

/* This file is responsible for all the supported commands within my shell */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h> 
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


// Clear Terminal //
int clr(char **args)
{
    system("clear");
    return 0;
}

// Quit command to exit shell //
int quit()
{
    exit(0);
}

// Pause command to have the ability to pause an already running program //
int pausing(char **args)
{
    if (!strcmp(args[0], "pause"))
    {
        printf("You have paused the current program, press enter to continue.\n");
        getchar();      
    }
    return 0;
}



// Lists of directories, using forks and background exec //

int dir(char **args)
{
    if(!strcmp(args[0], "dir"))
    {
        system("ls");
    }

    else if (!strcmp(args[1], "&"))
    {
        pid_t pid = 0;
        pid = fork();
        int i = 0;
        int background = 0;

        if (pid < 0)
        {
            fprintf(stderr, "Fork Failed");
        }

        else if (pid == 0)
        {
            execlp("ls", "ls", NULL);
            if (execvp(args[0], args) < 0)
            { 
                printf("Attempted to execute given command: Faield. \n"); 
                exit(0);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    return 0;
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
int environment(){

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
