all: clean mbootloader floppy boot

clean: output/
	rm -Rf output/
	mkdir output/
	mkdir output/bootloader
	mkdir output/kernel
	mkdir output/lib
mbootloader: bootloader/boot.asm bootloader/ExtendedProgram.asm
	nasm -f bin -o output/bootloader/bootloader bootloader/boot.asm
	nasm -f bin -o output/bootloader/ExtendedProgram bootloader/ExtendedProgram.asm
floppy: output/bootloader/bootloader output/bootloader/ExtendedProgram
	cat output/bootloader/bootloader output/bootloader/ExtendedProgram | dd of=output/bootsect bs=512 count=2880
boot:
	qemu-system-x86_64 output/bootsect
depencies:
	sudo apt-get install nasm -y
	sudo apt-get install gcc -y
	sudo apt-get install g++ -y
	sudo apt-get install mkisofs -y
clear: output/
	rm -Rf output
update_from_github:
	git pull