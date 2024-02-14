#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main(void) {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("#cisfun$ ");

        if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char *args[MAX_COMMAND_LENGTH];
            char *token = strtok(input, " ");
            int i = 0;
            while (token != NULL && i < MAX_COMMAND_LENGTH - 1) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            execvp(args[0], args);
            
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {

            int status;
            wait(&status);
        }
    }
    printf("\n");
    return 0;
}