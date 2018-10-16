# Adding a new system call into xv6

For this assignment, we are going to add a new system call: date

Let's start with **syscall.h** file. As you see below, there are already 21 system calls defined.

``` c
#define SYS_fork 1
#define SYS_exit 2
#define SYS_wait 3
.
.
.
#define SYS_close 21
```

Let's add the following line below.

``` c
#define SYS_date 22
```

Now we have to deal with **syscall.c** file. In this file, there's an array of function pointers inside this file with the function prototype **static int (\*syscalls[]) (void)**. 

``` c
static int (*syscalls[]) (void) = {
[SYS_fork]  sys_fork,
[SYS_exit]  sys_exit,
[SYS_wait]  sys_wait,
.
.
.
[SYS_close] sys_close,
};
```

It uses the number of system calls defined above as indexes for a pointer to each system call function defined elsewhere.

Let's add the following line.
``` c
[SYS_date]  sys_date,
```

It implies that if a system call with number 22 occures, the function pointed by the function pointer **sys_date** will be called.
