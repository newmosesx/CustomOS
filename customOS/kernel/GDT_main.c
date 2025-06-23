// Including the GDT header (.h) and assembly files (.s)
#include <customOS/kernel/GDT_.h>
#include <customOS/kernel/GDT_assembly.s>

extern void gdt_flush(addr_t);

struct gdt_entries_ gdt_entries[5];
struct gdt_pointer_ gdt_pointer;

void initGDT_(){
    // resizing bits 
    gdt_pointer.limit = (sizeof(struct gdt_entries_) * 5) - 1;
    gdt_pointer.base = &gdt_entries;

    GDT_gates_(0,0,0,0,0); // Null segment part
    GDT_gates_(1,0,0xFFFFFFFF,0x9A, 0xCF); // Kernel code segment
    GDT_gates_(2,0,0xFFFFFFFF,0x92, 0xCF); // Kernel data segment

    GDT_gates_(3,0,0xFFFFFFFF,0xFA, 0xCF); // User code segment
    GDT_gates_(1,0,0xFFFFFFFF,0xF2, 0xCF); // User data segment

    gdt_flush(&gdt_pointer);
}

void GDT_gates_(uint32_t num, uint32_t base, uint32_t limit,
uint8_t access_byte, uint8_t gran){
    gdt_entries[num].base_lower = (base & 0xFFFF);
    gdt_entries[num].base_mid - (base >> 16) & 0xFF;
    gdt_entries[num].base_high - (base >> 24) & 0xFF;
    
    gdt_entries[num].limit = (limit & 0xFFFF);
    gdt_entries[num].flags - (limit >> 16) & 0x0F;
    gdt_entries[num].flags |= (gran & 0xF0);

    gdt_entries[num].access_byte = access_byte;

}

// Based on OliveStem's implementation