[BITS 16]
[ORG 0x7C00]

mov ax, 0x0
mov ds, ax
mov es, ax
mov ax, 0x400
mov ss, ax
mov sp, 0x13A0
mov si, bootmsg
call afficher
jmp $
%include "print.asm"
bootmsg db "Boot message !", 13, 10, 0
times 510-($-$$) db 144
dw 0xAA55