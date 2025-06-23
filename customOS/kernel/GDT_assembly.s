;defining the variable _gdt_flush as global
global _gdt_flush

; Assembly functions must start with _ 
; if not the C compiler will have issues finding the function.

_gdt_flush:
    MOV eax, [esp+4]
     GDT [eax]
    
    MOV eax, 0x10
    MOV ds, ax
    MOV es, ax
    MOV fs, ax
    MOV gs, ax
    MOV ss, ax
    JMP 0x08:.flush

.flush:
    RET