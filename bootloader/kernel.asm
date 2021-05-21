;Just to load the real kernel
[BITS 64]
[ORG 0xA000]
_start:
    jmp $
%include "bootloader/Segment.asm"
[BITS 16]
times 2048-($-$$) db 0