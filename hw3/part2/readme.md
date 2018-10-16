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

So, now we have to implement this function **sys_date**. Before implementation, let's declare **sys_date** in this file

``` c
extern int sys_fork(void);
extern int sys_exit(void);
extern int sys_wait(void);
.
.
.
extern int sys_close(void);
extern int sys_date(void);
```

Actual system call functions are defined in two files: **sysproc.c** and **sysfile.c**. Since **sysfile.c** contains system calls related to file system, and others for rest, we are going to define function in **sysproc.c**.

Let's open the file and add function implementation at the end of the file
``` c
int sys_date(void){
  struct rtdate *r;
  if(argptr(0, (void *)&r, sizeof(&r)) < 0)
    return -1;
  cmostime(r);
  return 0;
}
``
