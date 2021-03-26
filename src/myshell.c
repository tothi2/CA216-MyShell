/* Name: Imrich Toth */
/* Student number: 19307456 */
/* I acknowledge the DCU integrity policy, this code was fully written by myself */


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

        FILE *fname = fopen(argv[1], "r"); //opening the file in the argument //

        char *line = calloc(MAX_ARGS, sizeof(char*));                                         
        char ** command;

    
        while (fgets(line, MAX_BUFFER, fname))
        {

            execute_command(split_lines(line)); // running each command in the file, line by line //

        }

        fclose(fname); // close the file once we are done reading each command //
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
