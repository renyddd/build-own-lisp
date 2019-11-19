#include <stdio.h>
#include <stdlib.h>

// if we are compiling on windows compile these functions.
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

// fake readline function.
char *readline(char *prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

// fake add_history function.
void add_history(char *unused) {}

// otherwise include the editline headers.
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif

int main(int argc, char** argv) {

    // print information.
    puts("Lispy version 0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while (1) {
        // output our prompt and get input.
        char *input = readline("lispy> ");

        // add input to history.
        add_history(input);

        // echo input back to user.
        printf("NO, you are %s\n", input);

        // free retrieved input.
        free(input);

    }

    return 0;
}
