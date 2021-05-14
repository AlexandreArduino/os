all: init_dirs mbootloader boot

init_dirs:
	rm -Rf ../output/
	mkdir ../output/
	mkdir ../output/bootloader
	mkdir ../output/lib/

mbootloader: boot.asm ExtendedProgram.asm
	gcc -c ../lib/screen.c -o ../output/lib/screen.o
	nasm -f bin boot.asm -o ../output/bootloader/bootloader
	nasm -f bin ExtendedProgram.asm -o ../output/bootloader/ExtendedProgram
	cat ../output/bootloader/bootloader ../output/bootloader/ExtendedProgram  | dd of=../output/os bs=512 count=2880
	mkisofs -o ../output/os.iso ../output/os
boot: ../output/os
	qemu-system-x86_64 ../output/os
clean:
	rm -Rf ../output/