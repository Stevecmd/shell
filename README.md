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
shell# ./commandlinetoav
Number of words: 5
Words:
This
is
a
test
string
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

The system call `fork` (man 2 `fork`) creates a new child process, almost identical to the parent (the process <br />
that calls `fork`). Once `fork` successfully returns, two processes continue to run the same program, but with <br />
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
Similarly, Using the return value of fork, it is possible to know if <br />
the current process is the father or the child: fork will return 0 to the child, <br />
and the PID of the child to the father. <br />
See: `fork2.c`

Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic fork2.c -o fork2
```
Run the program:
```sh
./fork2
```
Sample output:
```sh
shell# ./fork2
My pid is 192
(192) 193, I am your father
My pid is 193
(193) Nooooooooo!
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

## Exercise: fork + wait + execve
Write a program that executes the command `ls -l /tmp` in 5 different child processes. <br /> 
Each child should be created by the same process (the father). <br />
Wait for a child to exit before creating a new child. 

Compile the code:
```sh
gcc -Wall -Wextra -Werror -pedantic forkwaitexecve.c -o forkwaitexecve
```
Run the program:
```sh
./forkwaitexecve
```
Sample output:
```sh
shell# ./forkwaitexecve
Child process 1: PID 220
total 0
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.DAOEzJT0J6
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.dOKjikw0Ig
drwx------ 2 root  root  22 Mar 30  2022 tmpztrs6ymg
Child process 2: PID 221
total 0
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.DAOEzJT0J6
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.dOKjikw0Ig
drwx------ 2 root  root  22 Mar 30  2022 tmpztrs6ymg
Child process 3: PID 222
total 0
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.DAOEzJT0J6
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.dOKjikw0Ig
drwx------ 2 root  root  22 Mar 30  2022 tmpztrs6ymg
Child process 4: PID 223
total 0
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.DAOEzJT0J6
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.dOKjikw0Ig
drwx------ 2 root  root  22 Mar 30  2022 tmpztrs6ymg
Child process 5: PID 224
total 0
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.DAOEzJT0J6
drwx------ 2 mysql mysql  6 Mar 30  2022 tmp.dOKjikw0Ig
drwx------ 2 root  root  22 Mar 30  2022 tmpztrs6ymg
```
## Exercise: super simple shell
```sh
gcc -Wall -Wextra -Werror -pedantic supersimpleshell.c -o supersimpleshell
```
Run the program:
```sh
./supersimpleshell
```
Sample output:
```sh

```