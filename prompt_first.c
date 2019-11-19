#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#include <editline/history.h>

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
