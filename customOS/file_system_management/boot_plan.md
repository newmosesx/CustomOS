Kernel Entry and Global Descriptor Table (GDT): Once the bootloader hands off control, the kernel is running. The very first thing to do is set up a new GDT. The GDT is a data structure that defines memory segments for the CPU, controlling what code has access to what parts of memory. This is the first step in establishing memory protection and moving the CPU into a protected 32-bit or 64-bit mode.


Basic Hardware Interaction:

    Screen Output: Write a simple driver to print text to the screen. The easiest way is using the legacy VGA text-mode buffer, which is a memory-mapped area at 0xB8000. Writing characters here makes them appear on screen. This gives us the printf debugging capability.

    Interrupt Handling (IDT): Set up the Interrupt Descriptor Table (IDT). The IDT tells the CPU where to find the code to handle interrupts (from hardware) and exceptions (from software errors like dividing by zero). This is a critical step for stability and for interacting with hardware.