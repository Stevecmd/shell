#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    if (argc != 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        return 1;
    }

    pid_t max_pid = sysconf(_SC_CHILD_MAX);
    printf("Maximum process ID: %d\n", max_pid);

    return 0;
}
