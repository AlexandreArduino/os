ReadDisk:
	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 51
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02
	int 0x13
	jc DiskReadFailed
	ret

BOOT_DISK:
	db 0
DiskReadErrorString:
	db "Disk Read failed!", 13, 10, 0
DiskReadFailed:
	mov si, DiskReadErrorString
	call printasm
	jmp $