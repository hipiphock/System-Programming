# Adding a new system call into xv6

For this assignment, we are going to add a new system call: date

Let's start with syscall.h file. As you see below, there are already 21 system calls defined.
``` c
#define SYS_fork 1
#define SYS_exit 2
#define SYS_wait 3
.
.
.
#define SYS_close 21
```
