#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    printf("$ ");

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("%s", line);
        printf("$ ");

        free(line);
        line = NULL;
        len = 0;
    }

    if (line != NULL) {
        free(line);
    }

    return 0;
}
