EXTERN isr_default_int, isr_clock_int, isr_kbd_int
GLOBAL _asm_default_int, _asm_irq_0, _asm_irq_1
_asm_default_int:
    call isr_default_int
    mov al, 0x20
    out 0x20, al
    iret
_asm_irq_0:
    call isr_clock_int
    mov al, 0x20
    out 0x20, al
    iret
_asm_irq_1:
    call isr_kbd_int
    mov al, 0x20
    out 0x20, al
    iret