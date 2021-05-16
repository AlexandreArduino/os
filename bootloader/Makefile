all: clean mbootloader floppy boot

clean: ../output/
	clear
	rm -Rf ../output/
	mkdir ../output/
	mkdir ../output/bootloader
	mkdir ../output/lib/
	mkdir ../output/kernel/

mbootloader: boot.asm ExtendedProgram.asm ../kernel/kernel.cpp
	nasm -f bin -o ../output/bootsect boot.asm
	#nasm -f bin -o ../output/bootloader/ExtendedProgram ExtendedProgram.asm	
	#cat ../output/bootloader/bootloader ../output/bootloader/ExtendedProgram | dd of=../output/bootsect bs=512 count=2880
	nasm ExtendedProgram.asm -f elf64 -o ../output/bootloader/ExtendedProgram.o
	x86_64-elf-gcc -ffreestanding -mno-red-zone -m64 -c "../kernel/kernel.cpp" -o "../output/kernel/kernel.o"
	ld -o ../output/kernel/kernel.tmp -Ttext 0x8DA6 ../output/bootloader/ExtendedProgram.o ../output/kernel/kernel.o
	objcopy -O binary ../output/kernel/kernel.tmp ../output/kernel.bin
floppy: ../output/bootsect ../output/kernel.bin
	#cat ../output/bootsect ../output/mkernel | dd of=../output/os bs=512 count=2880
	cat ../output/bootsect ../output/kernel.bin | dd of=../output/os

boot: ../output/os
	qemu-system-x86_64 ../output/os
boot_bootloader: ../output/bootsect
	qemu-system-x86_64 ../output/bootsect
boot_kernel_only: ../output/kernel.bin
	qemu-system-x86_64 ../output/kernel.bin