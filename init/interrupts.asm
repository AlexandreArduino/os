[BITS 64]
[EXTERN DefaultInterruptHandler]
[GLOBAL DefaultInterrupt]
%macro PUSHALL 0
    push rax
    push rcx
    push rdx
    push r8
    push r9
    push r10
    push r11
%endmacro
%macro POPALL 0
    pop r11
    pop r10
    pop r9
    pop r8
    pop rdx
    pop rcx
    pop rax
%endmacro
DefaultInterrupt:
    PUSHALL
    call DefaultInterruptHandler
    POPALL
    mov al, 0x20
    out 0x20, al
    iretq