# shell
Everything you need to know to start coding your own shell
## Exercises
0. getppid
Getting the process ID: <br />
Compile the code:
```sh
gcc -Wall -Werror -pedantic pid.c -o mypid && ./mypid
```
Run the program:
```sh
./mypid
```

1. /proc/sys/kernel/pid_max
Get the max PID: <br />
Compile the code:
```sh
gcc -Wall -Werror -pedantic pid_max.c -o pid_max && ./pid_max
```
Run the code:
```sh
./pid_max
```
Sample output:
```sh
Maximum process ID: -1
```