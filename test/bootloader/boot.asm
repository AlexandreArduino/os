[BITS 16]

mov ax, 0x7C00
mov ds, ax
mov es, ax
mov ax, 0x8000
mov ss, ax
mov sp, 0xf000

mov si, bootmsg
call afficher

bootmsg: db "Hello World !", 13, 10
%include "print.asm"
jmp $
    times 510-($-$$) db 144
    dw 0xAA55