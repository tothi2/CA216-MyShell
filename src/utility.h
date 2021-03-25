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


// This function job is to split the lines into tokens //
char **split_lines(char *line)
{
  int size = MAX_ARGS;
  int pos = 0;
  char **toks = malloc(size * sizeof(char*)); // these tokens need to handle memory so I use malloc here //
  char *tok;
  tok = strtok(line, SEPARATORS);
  while (tok != 0)
  {
    toks[pos] = tok;
    pos++;
    if (!toks)
    {
        fprintf(stderr, "Error\n"); //If no arguments are produced then an error message will be printed //
        exit(0);
    }
    if (pos >= size) {
      size += MAX_ARGS;
      toks = realloc(toks, sizeof(char*) * size);
    }
    tok = strtok(NULL, SEPARATORS);
  }
  toks[pos] = NULL;
  return toks;
}





// ths will be used to execute internal commands //
int execute_command(char *args[])
{
    char * commands[] = { "clr", "quit", "dir", "environ", "echo", "cd", "pause"}; // list of commands written in commands.c
    int (*functions[]) (char **) = { &clr, &quit, &dir, &environment, &echo, &changedir, &pausing};
    
    // the input must match the function name in order for the command to be executed
    for (int i = 0; commands[i]; i++)
    {

        if (!strcmp(args[0], commands[i]))
        {
          return (*functions[i])(args);
        }
    }

}
