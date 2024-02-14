#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

char **split_string(const char *str, int *num_words) {
    char **words = malloc(MAX_WORDS * sizeof(char *));
    if (words == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    *num_words = 0;

    char *token = strtok((char *)str, " \t\n");
    while (token != NULL) {
        words[*num_words] = malloc((strlen(token) + 1) * sizeof(char));
        if (words[*num_words] == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        strcpy(words[*num_words], token);

        (*num_words)++;

        if (*num_words >= MAX_WORDS) {
            fprintf(stderr, "Maximum number of words exceeded\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, " \t\n");
    }

    return words;
}

int main() {
    char str[] = "This is a test string";
    int num_words;
    char **words = split_string(str, &num_words);

    printf("Number of words: %d\n", num_words);
    printf("Words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    free(words);
    return 0;
}