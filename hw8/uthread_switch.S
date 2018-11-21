	.text

/* Switch from current_thread to next_thread. Make next_thread
 * the current_thread, and set next_thread to 0.
 * Use eax as a temporary register; it is caller saved.
 */
	.globl thread_switch
thread_switch:
	/* YOUR CODE HERE */
    
    pushal      // store current thread

    movl current_thread, %eax   // load address of current thread
    movl %esp, (%eax)           // save esp register in stack pointer of thread

    movl next_thread, %eax      // load address of next thread
    movl (%eax), %esp           // load stack pointer of thread in esp register

    movl %eax, current_thread   // next thread -> current_thread
    
    movl $0x0, next_thread      // next_thread = 0

    popal                       // restore register from stack

	ret				/* pop return address from stack */
