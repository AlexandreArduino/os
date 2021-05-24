all: clean cbootloader ckernel clink cboot

clean: output/
	clear
	rm -Rf output/
	mkdir output/
	mkdir output/bootloader
	mkdir output/kernel
	mkdir output/lib
	mkdir output/test
	mkdir output/test/bootloader
mbootloader: bootloader/boot.asm bootloader/ExtendedProgram.asm
	nasm -f bin -o output/bootloader/bootloader bootloader/boot.asm
	nasm -f bin -o output/bootloader/ExtendedProgram bootloader/ExtendedProgram.asm
	nasm -f bin -o output/bootloader/kernel bootloader/kernel.asm
kernel: bootloader/kernel.asm
	echo Kernel section
	#nasm -f elf64 -o output/kernel/kernel.o bootloader/kernel.asm
floppy: output/bootloader/bootloader output/bootloader/ExtendedProgram
	cat output/bootloader/bootloader output/bootloader/ExtendedProgram output/bootloader/kernel | dd of=output/bootsect bs=512 count=2880
boot:
	qemu-system-x86_64 output/bootsect
boot_bootloader:
	qemu-system-x86_64 output/bootloader/bootloader
depencies:
	sudo apt-get install nasm gcc g++ mkisofs -y
clear: output/
	rm -Rf output
update_from_github:
	git pull

cbootloader: bootloader/boot.asm bootloader/ExtendedProgram.asm bootloader/kernel.asm
	nasm -f bin -o output/bootloader/bootloader bootloader/boot.asm
	nasm -f bin -o output/bootloader/ExtendedProgram bootloader/ExtendedProgram.asm
	cat output/bootloader/bootloader output/bootloader/ExtendedProgram | dd of=output/bootsect bs=512 count=2880
ckernel: kernel/kernel.cpp kernel/screen.cpp
	x86_64-elf-gcc -c kernel/kernel.cpp -o output/kernel/kernel.o
	x86_64-elf-g++ -c kernel/screen.cpp -o output/kernel/screen.o
clink: output/bootsect
	ld --oformat binary -Ttext 8600 output/kernel/kernel.o output/kernel/screen.o -o output/ckernel
	cat output/bootsect output/ckernel | dd of=output/os bs=512 count=2880
cboot: output/os
	qemu-system-x86_64 output/os