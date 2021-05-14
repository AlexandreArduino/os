[BITS 16]
[ORG 0x7c00]

    mov ax, 0x0
    mov ds, ax
    mov es, ax
    mov ax, 0x8000
    mov ss, ax
    mov sp, 0xf000
    mov si, boot_started
    call afficher
    mov si, reading_disk
    call afficher
    mov [BOOT_DISK], dl
    call ReadDisk
    jmp PROGRAM_SPACE
end:
    jmp end

%include "print.asm"
%include "DiskRead.asm"

boot_started: db "Bootloader started !", 13, 10, 0
reading_disk: db "Reading disk ...", 13, 10, 0

times 510-($-$$) db 144
dw 0xAA55