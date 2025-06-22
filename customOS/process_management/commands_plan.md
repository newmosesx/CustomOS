The User Shell and C Standard Library:

    Shell: Write a simple command-line shell that runs as a user program. It will use system calls to execute other programs (exec), manage processes (fork, wait), and interact with files (open, read).

    libc: To compile complex programs for your OS, you'll need to create your own C Standard Library (libc) that translates standard functions (printf, malloc, fopen) into your kernel's specific system calls.