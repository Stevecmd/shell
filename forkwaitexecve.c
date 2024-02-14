#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            printf("Child process %d: PID %d\n", i + 1, getpid());

            char *args[] = {"ls", "-l", "/tmp", NULL};
            if (execve("/bin/ls", args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }
    return 0;
}