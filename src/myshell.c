/* code taken from Lab 4B, used as a starting point */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "commands.h"
#include "utility.h"


#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

int main (int argc, char ** argv)
{
    char shellpath[MAX_BUFFER];                // shell path
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = ">" ;                      // shell prompt
    
    strcat(shellpath, getenv("PWD")); // gets present working directories environment.
    strcat(shellpath, "/myshell"); //finds path of the shell
    
    init(); // this was defined in utility.h and contains my welcome message
    
    if (argv[1] != NULL)
    {

        FILE *batchfile = fopen(argv[1], "r");

        char *line = calloc(MAX_ARGS, sizeof(char*));                                         
        char ** command;

    
        if (batchfile == NULL)
        {
            printf("Error Reading File\n");
        }

        while (fgets(line, 255, batchfile))
        {
            command = split_line(line);
            execute_command(command);
            sleep(4);
        }

        fclose(batchfile);
    }


/* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin))
    { 
        /* get command line from input */
        fputs (prompt, stdout);                // write prompt
        if (fgets (buf, MAX_BUFFER, stdin )) 
        {
            arg = args;
            args = split_line(buf);
            if (args[0] != NULL)
            {

                if (!strcmp(args[0], "pause"))
                {
                    pause_prog();
                }
                else{
                    if (!strcmp(args[0], "myshell")){
                        external_command(args);
                    }
                    else
                    {
                        execute_command(args);
                    }
            }
        }
    }
}
