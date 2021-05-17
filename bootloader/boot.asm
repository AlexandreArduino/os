%include "bootloader/Segment.asm"
[BITS 16]
[ORG BOOTLOADER_SPACE]

    mov ax, 0x0
    mov ds, ax
    mov es, ax
    mov ax, TOP_STACK
    mov ss, ax ;Start of the stack
    mov sp, BOTTOM_STACK
    mov si, author
    call printasm
    mov si, boot_started
    call printasm
    mov si, reading_disk
    call printasm
    mov [BOOT_DISK], dl
    call ReadDisk
    jmp PROGRAM_SPACE
end:
    jmp end

%include "bootloader/print.asm"
%include "bootloader/DiskRead.asm"

author: db "BAALBAKY Alexandre 05/2021 - 05/2021", 13, 10, 0
boot_started: db "Bootloader started !", 13, 10, 0
reading_disk: db "Reading disk ...", 13, 10, 0

times 510-($-$$) db 144
dw 0xAA55