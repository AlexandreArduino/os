[ORG 0x8DA6]

mov si, ExtendedSpaceSuccess
call printasm
mov si, ProtectedModeLoading
call printasm
jmp EnterProtectedMode

%include "bootloader/gdt.asm"
%include "bootloader/print.asm"


EnterProtectedMode:
	call EnableA20
	mov si, DisablingInterrupts
	call printasm
	cli
	mov si, LoadingGDT
	call printasm
	lgdt [gdt_descriptor]
	mov si, RegisterCR0
	call printasm
	mov si, End16bits
	call printasm
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

End16bits: db "Leaving 16 bits ...", 13, 10, 0

[BITS 32]

%include "bootloader/CPUID.asm"

ProtectedMode:
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	call DetectCPUID
	call DetectLongMode
	jmp $
times 2048-($-$$) db 0