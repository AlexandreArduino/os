all: clean mbootloader boot

clean: ../output/
	clear
	rm -Rf ../output/
	mkdir ../output/
	mkdir ../output/bootloader
	mkdir ../output/lib/

mbootloader: boot.asm ExtendedProgram.asm
	nasm -f bin -o ../output/bootloader/bootloader boot.asm
	nasm -f bin -o ../output/bootloader/ExtendedProgram ExtendedProgram.asm
	cat ../output/bootloader/bootloader ../output/bootloader/ExtendedProgram | dd of=../output/bootsect bs=512 count=2880
boot: os
	qemu-system-x86_64 ../output/bootsect