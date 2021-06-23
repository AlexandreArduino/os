CCOMPILER = gcc
CFLAGS =  -w -Wall -O0 -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -fpermissive
COMPILE_LINE = $(CCOMPILER) $(CFLAGS)
LDFILE = link.ld
MAIN_ROUTINE = clean cbootloader ckernel cinit cbootprocess ctest clink cboot
ASMCOMPILER = nasm
ASMFLAGS = -f elf64
ASMFLAGS_BOOTLOADER = -f bin
all: $(MAIN_ROUTINE)

clean:
	clear
	rm -Rf output/
	mkdir output/
	mkdir output/bootloader
	mkdir output/kernel
	mkdir output/kernel/screen
	mkdir output/kernel/hardware
	mkdir output/lib
	mkdir output/dev
	mkdir output/test
	mkdir output/init
	mkdir output/boot
depencies:
	sudo apt-get install nasm gcc g++ -y
clear: output/
	rm -Rf output

cbootloader: bootloader/boot.asm bootloader/ExtendedProgram.asm bootloader/kernel.asm
	$(ASMCOMPILER) $(ASMFLAGS_BOOTLOADER) -o output/bootloader/bootloader bootloader/boot.asm
	$(ASMCOMPILER) $(ASMFLAGS_BOOTLOADER) -o output/bootloader/ExtendedProgram bootloader/ExtendedProgram.asm
	cat output/bootloader/bootloader output/bootloader/ExtendedProgram | dd of=output/bootsect bs=512 count=2880
ckernel: kernel/kernel.cpp
	$(CCOMPILER) $(CFLAGS) -c kernel/kernel.cpp -o output/kernel/kernel.o 
	$(CCOMPILER) $(CFLAGS) -c kernel/screen/screen.cpp -o output/kernel/screen/screen.o
	$(CCOMPILER) $(CFLAGS) -c kernel/hardware/IO.cpp -o output/kernel/hardware/IO.o
	# $(CCOMPILER) $(CFLAGS) -c kernel/screen/log.cpp -o output/kernel/screen/log.o
	$(CCOMPILER) $(CFLAGS) -c lib/integer.cpp -o output/lib/integer.o
	$(CCOMPILER) $(CFLAGS) -c lib/math.cpp -o output/lib/math.o
	$(CCOMPILER) $(CFLAGS) -c lib/string.cpp -o output/lib/string.o
	$(CCOMPILER) $(CFLAGS) -c kernel/utils.cpp -o output/kernel/utils.o
	$(CCOMPILER) $(CFLAGS) -c kernel/screen/TextCursor.cpp -o output/kernel/screen/TextCursor.o
	$(COMPILE_LINE) -c lib/string.cpp -o output/lib/string.o
	$(COMPILE_LINE) -c lib/float.cpp -o output/lib/float.o
	$(COMPILE_LINE) -c kernel/hardware/pic.cpp -o output/kernel/hardware/pic.o
ctest:
	$(COMPILE_LINE) -c test/math.cpp -o output/test/math.o
	$(COMPILE_LINE) -c test/screen.cpp -o output/test/screen.o
cinit:
	# $(COMPILE_LINE) -c init/kernel.cpp -o output/init/kernel.o
	$(COMPILE_LINE) -c init/gdt.cpp -o output/init/gdt.o
	$(ASMCOMPILER) $(ASMFLAGS) init/gdt.asm -o output/init/gdt_asm.o
	$(COMPILE_LINE) -c init/interrupts.cpp -o output/init/interrupts.o
	$(ASMCOMPILER) $(ASMFLAGS) init/interrupts.asm -o output/init/interruptsasm.o
cbootprocess:
	$(COMPILE_LINE) -c boot/BootInfos.cpp -o output/boot/BootInfos.o
	$(COMPILE_LINE) -c boot/kernel.cpp -o output/boot/kernel.o
clink: output/bootsect
	# x86_64-elf-ld -T"$(LDFILE)"
	ld -T"$(LDFILE)"
	cat output/bootsect output/ckernel | dd of=output/os bs=512 count=2880
	cat output/bootsect output/ckernel | dd of=output/os.bin bs=512 count=2880
	cp output/bootsect output/bootloader/bootsect
	cp output/ckernel output/kernel/ckernel
	rm output/bootsect
	rm output/ckernel
cboot: output/os
	qemu-system-x86_64 output/os
cboot_infos: output/os
	qemu-system-x86_64 output/os -d int -no-reboot -no-shutdown