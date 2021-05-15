all: clean mbootloader floppy boot

clean: ../output/
	clear
	rm -Rf ../output/
	mkdir ../output/
	mkdir ../output/bootloader
	mkdir ../output/lib/
	mkdir ../output/kernel/

mbootloader: boot.asm ExtendedProgram.asm
	nasm -f bin -o ../output/bootloader/bootloader boot.asm
	nasm -f bin -o ../output/bootloader/ExtendedProgram ExtendedProgram.asm	
	cat ../output/bootloader/bootloader ../output/bootloader/ExtendedProgram | dd of=../output/bootsect bs=512 count=2880
kernel: ../kernel/kernel.c
	nasm -f bin -o ../output/mkernel ../kernel/kernel.asm 
	#gcc -c ../kernel/kernel.c -o ../output/kernel/kernel.o
	#ld --oformat binary -Ttext 0x13880 ../output/kernel/kernel.o -o ../output/mkernel

floppy: ../output/bootsect ../output/mkernel
	cat ../output/bootsect ../output/mkernel | dd of=../output/os bs=512 count=2880

boot: ../output/os
	qemu-system-x86_64 ../output/os