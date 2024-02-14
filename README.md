# shell
Everything you need to know to start coding your own shell
### Exercises
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

Exercises
0. av

Write a program that prints all the arguments, without using `ac`.
1. Read line

Write a program that prints `"$ "`, wait for the user to enter a command, prints it on the next line. <br />

man 3 `getline`

**important** make sure you read the man, and the `RETURN VALUE` section, in order to know when to stop reading. <br />
Keyword: `“end-of-file”`, or `EOF` (or `Ctrl+D`). <br />
Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic prompt.c -o prompt
```
Run the program:
```sh
./prompt
```
Sample output:
```sh
./prompt 
$ cat prompt.c
cat prompt.c
```

2. command line to av

Write a function that splits a string and returns an array of each word of the string.

man `strtok`
File: `commandlinetoav`
Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic commandlinetoav.c -o commandlinetoav
```
Run the program:
```sh
./commandlinetoav
```
Sample output:
```sh

```


## Executing a program
The system call `execve` allows a process to execute another program (man 2 `execve`). Note that this system <br /> 
call does load the new program into the current process’ memory in place of the “previous” program: on <br /> 
success `execve` does not return to continue the rest of the “previous” program. <br />

**Warning:** in this example, `execve` is used without the current environment (last argument), don’t forget to add it in your Shell! <br />
See `exec.c` <br />

Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic exec.c -o exec
```
Run the program:
```sh
./exec
```
Sample output:
```sh
Before execve
total 64
drwxr-xr-x 1 root root 20480 Mar 30  2022 bin
drwxr-xr-x 2 root root     6 Apr 15  2020 games
drwxr-xr-x 1 root root  4096 Mar 30  2022 include
drwxr-xr-x 1 root root  4096 Mar 30  2022 lib
drwxr-xr-x 1 root root  4096 Mar 30  2022 lib32
drwxr-xr-x 1 root root    34 Mar 30  2022 lib64
drwxr-xr-x 1 root root    95 Mar 30  2022 libexec
drwxr-xr-x 1 root root  4096 Mar 30  2022 libx32
drwxr-xr-x 1 root root    19 Mar 16  2022 local
drwxr-xr-x 1 root root  4096 Mar 30  2022 sbin
drwxr-xr-x 1 root root  4096 Mar 30  2022 share
drwxr-xr-x 2 root root     6 Apr 15  2020 src
```

## Creating processes

The system call fork (man 2 fork) creates a new child process, almost identical to the parent (the process <br />
that calls fork). Once fork successfully returns, two processes continue to run the same program, but with <br />
different stacks, datas and heaps. <br />
see `fork.c`.

Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic fork.c -o fork
```
Run the program:
```sh
./fork
```
Sample output:
```sh
Before fork
After fork
My pid is 120
After fork
My pid is 121
```

## Wait

The `wait` system call (man 2 `wait`) suspends execution of the calling process until one of its children terminates.
See `wait.c`

Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic wait.c -o wait
```
Run the program:
```sh
./wait
```
Sample output:
```sh
Wait for me, wait for me
Oh, it's all better now
```