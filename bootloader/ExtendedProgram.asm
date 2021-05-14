[ORG 0x7e00]
mov si, ExtendedSpaceSuccess
call afficher
mov si, ProtectedModeLoading
call afficher
jmp EnterProtectedMode

%include "gdt.asm"
%include "print.asm"


EnterProtectedMode:
	mov si, DisablingInterrupts
	call afficher
	cli
	mov si, LoadingGDT
	call afficher
	lgdt [gdt_descriptor]
	mov si, RegisterCR0
	call afficher
	mov eax, cr0
	or al, 1
	mov cr0, eax
	jmp codeseg:ProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

ExtendedSpaceSuccess: db "Extended Space successfully loaded !", 13, 10, 0

ProtectedModeLoading: db "Loading Protected Mode ...", 13, 10, 0

DisablingInterrupts: db "Disabling interrupts ...", 13, 10, 0

LoadingGDT: db "Loading GDT ...", 13, 10, 0

RegisterCR0: db "Modifying CR0 bit ...", 13, 10, 0

[BITS 32]

EXTERN putchar
GLOBAL _start

ProtectedMode:
	mov eax, 'A'
	push eax
	call putchar
	pop eax
	jmp $
times 2048-($-$$) db 0