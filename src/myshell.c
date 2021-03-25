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
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = ">" ;                      // shell prompt
    
    init(); // this was defined in utility.h and contains my welcome message
    
    if (argv[1] != NULL) // if the second argument is not null then we must open that file and read it. //
    {

        FILE *fname = fopen(argv[1], "r");

        char *line = calloc(MAX_ARGS, sizeof(char*));                                         
        char ** command;

    
        while (fgets(line, MAX_BUFFER, fname))
        {

            execute_command(split_lines(line));

        }

        fclose(fname);
    }

    while (!feof(stdin))
    { 
        printf("%s$ ", getenv("PWD"));
        fputs(prompt, stdout); // show prompt
        if (fgets (buf, MAX_BUFFER, stdin ))
        {
            //simply executes the commands.
            execute_command(split_lines(buf));
        }
    }
}
