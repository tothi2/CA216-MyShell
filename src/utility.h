#define MAX_BUFFER 1024                        // max line buffer
#define MAX_ARGS 64                            // max # args
#define SEPARATORS " \t\n"                     // token sparators

int myshell(char *args[]);


// personalized shell loading screen //

void init()
{
    printf(" *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf("*  *  *  Welcome to Imrichs Shell *  *  *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * *\n");
    printf(" *  *  *  *  *  *  *  *  *  *  *  *  *  *\n");
    sleep(4);

}


// ths will be used to execute internal commands //
int execute_command(char *args[])
{
    char * commands[] = { "clr", "quit", "dir", "environ", "echo", "cd"}; // list of commands written in commands.c
    int (*functions[]) (char **) = { &clr, &quit, &dir, &environment, &echo, &changedir};
    
    // the input must match the function name in order for the command to be executed
    for (int i = 0; commands[i]; i++)
    {

        if (!strcmp(args[0], commands[i]))
        {
          return (*functions[i])(args);
        }
    }

}
