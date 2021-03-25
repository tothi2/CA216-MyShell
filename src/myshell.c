/* code taken from Lab 4B, used as a starting point */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include 'commands.c'

#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

int main (int argc, char ** argv)
{
    char buf[MAX_BUFFER];                      // line buffer
    char * args[MAX_ARGS];                     // pointers to arg strings
    char ** arg;                               // working pointer thru args
    char * prompt = ">" ;                      // shell prompt

/* keep reading input until "quit" command or eof of redirected input */

    while (!feof(stdin))
    { 
        /* get command line from input */
        fputs (prompt, stdout);                // write prompt
        if (fgets (buf, MAX_BUFFER, stdin )) 
        { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf,SEPARATORS);   // tokenize input
            while ((*arg++ = strtok(NULL,SEPARATORS)));
            // last entry will be NULL if (args[0]) 
            {                     // if there's anything there
            /* check for internal/external command */
            if (!strcmp(args[0],"clear")) 
            { // "clear" command
                system("clear");
                continue;
            }
            
            if (!strcmp(args[0],"quit"))   // "quit" command
                break;                     // break out of 'while' loop

            /* else pass command onto OS (or in this instance, print them out) */

            arg = args;
            while (*arg) fprintf(stdout,"%s ",*arg++);
                fputs ("\n", stdout);
            }
        }
    }
return 0; 
}