%include "bootloader/Segment.asm"

[BITS 64]
GLOBAL _start
_start:
    mov [VideoRAM_start], byte 'H'
    jmp $