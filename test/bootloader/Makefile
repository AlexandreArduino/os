all: bootloader floppy boot

bootloader: boot.asm
	nasm -f bin -o ../../output/test/bootloader/boot boot.asm
	nasm -f elf64 -o ../../output/test/bootloader/boot.o boot.asm
floppy: ../../output/test/bootloader/boot
	cat ../../output/test/bootloader/boot | dd of=../../output/test/bootsect bs=512 count=2880
boot: ../../output/test/bootsect
	qemu-system-x86_64 ../../output/test/bootsect