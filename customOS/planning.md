[Order]
Phase
Step
Order	
What it Unlocks	
Why it's in this order


1. 
    Bootstrapping	
    Bootloader & GDT | Interrupts & I/O
    1 | 2
    Your code running on the CPU. | Debugging and hardware interaction.
    You can't do anything until your code is loaded and running. | You need interrupts to handle timers and device input.
				

2. 
    Core Kernel	
    Memory Management | Scheduler
    3 | 4
    Safe memory allocation.	| Multitasking.
    You cannot create a process without allocating memory for it first. | The scheduler relies on a timer interrupt and a memory manager.

3. 
    Userland
    System Calls | First User Process
    5 | 6
    A secure kernel API. | Running applications.
    User programs need a safe way to request kernel services. | This validates the entire core kernel (memory, scheduling, syscalls).
	

4. 
    Expansion
    Storage Driver | Filesystem | Shell & libc
    7 | 8 | 9
    Access to persistent storage. | File management. | A usable user environment.
    You need to talk to the disk before you can manage files on it.| A filesystem is a layer of abstraction on top of a raw storage device. | The shell uses all the underlying features to create an interactive system. 