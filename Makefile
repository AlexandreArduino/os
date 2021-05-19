all: clean mbootloader kernel floppy boot

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
floppy: output/bootloader/bootloader output/bootloader/ExtendedProgram
	cat output/bootloader/bootloader output/bootloader/ExtendedProgram | dd of=output/bootsect bs=512 count=2880
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