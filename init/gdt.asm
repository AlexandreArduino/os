[BITS 64]
LoadGDT:
    lgdt [rdi]
    jmp [0x08:EndGDTLoad]
EndGDTLoad:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    pop rdi ;Return adress
    mov rax ,0x08
    push rax
    push rdi
    retfq
GLOBAL LoadGDT