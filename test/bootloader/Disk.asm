LoadKernel:
    xor ax, ax
    int 0x13
    push es
    mov ax, 0x2500
    mov es, ax
    mov bx, 0
    mov ah, 2
    mov al, 2 ;Number 512 bytes sectors
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov dl, [bootdrv]
    int 0x13
    pop es
    jmp 0x2500:0
bootdrv: db 0