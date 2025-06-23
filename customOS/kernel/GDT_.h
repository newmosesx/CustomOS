#include <stdint.h>

// Base -  Where this memory segment space start.
// Limit - How big the segment is.



// Defining the Segment Descriptor
struct gdt_entries_{
    uint16_t limit; // We have a size of 16 bits in the lower segment part.
    uint16_t base_lower; // The lower 16 bits of the segment is the starting address.

    uint8_t base_mid; // The next 8 bits of the segment is the starting address.
    uint8_t access_byte; // This 8 bits determine the access rights / privilages.

    uint8_t flags; // This holds the 4 bits of the limits and the 4 flags, we can do this by splitting half.
    uint8_t base_high; // The final 8 bits of the segment is the starting address.
}__attribute__((packed)); // This tells the compiler "Do not add any padding bytes to this structure." The CPU expects this exact 16 and 8 byte layout.

// Defining the pointers to limit and base
struct gdt_pointer_{
    uint16_t limit; // The total size of the GDT
    uint16_t base; // The memory address where GDT starts
}__attribute__((packed)); // This tells the compiler "Do not add any padding bytes to this structure." The CPU expects this exact 16 and 8 byte layout.

// Defining the functions to initialize GDT
void initGDT_();
void GDT_gates_(uint32_t num, uint32_t base, uint32_t limit, uint8_t access_byte, uint8_t gran);