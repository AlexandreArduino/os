CCOMPILER = gcc
CFLAGS =  -w -Wall -O0 -fno-stack-protector -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./include -fpermissive
COMPILE_LINE = $(CCOMPILER) $(CFLAGS)
LDFILE = link.ld
MAIN_ROUTINE = clean cbootloader ckernel clink cboot
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
	$(CCOMPILER) $(CFLAGS) -c kernel/screen/log.cpp -o output/kernel/screen/log.o
	$(CCOMPILER) $(CFLAGS) -c lib/integer.cpp -o output/lib/integer.o
	$(CCOMPILER) $(CFLAGS) -c lib/math.cpp -o output/lib/math.o
	$(CCOMPILER) $(CFLAGS) -c lib/string.cpp -o output/lib/string.o
	#$(CCOMPILER) $(CFLAGS) -c dev/scroll.cpp -o output/dev/scroll.o
	#$(CCOMPILER) $(CFLAGS) -c dev/cast.cpp -o output/dev/cast.o
	#$(CCOMPILER) $(CFLAGS) -c dev/print.cpp -o output/dev/print.o
	$(CCOMPILER) $(CFLAGS) -c kernel/utils.cpp -o output/kernel/utils.o
	#$(CCOMPILER) $(CFLAGS) -c dev/cursor.cpp -o output/dev/cursor.o
	$(CCOMPILER) $(CFLAGS) -c kernel/screen/TextCursor.cpp -o output/kernel/screen/TextCursor.o
	#$(COMPILE_LINE) -c dev/integer.cpp -o output/dev/integer.o
	#$(COMPILE_LINE) -c dev/gdt.cpp -o output/dev/gdt.o
	$(COMPILE_LINE) -c kernel/gdt.cpp -o output/kernel/gdt.o
clink: output/bootsect
	x86_64-elf-ld -T"$(LDFILE)"
	cat output/bootsect output/ckernel | dd of=output/os bs=512 count=2880
	cp output/bootsect output/bootloader/bootsect
	cp output/ckernel output/kernel/ckernel
	rm output/bootsect
	rm output/ckernel
cboot: output/os
	qemu-system-x86_64 output/os
cboot_infos: output/os
	qemu-system-x86_64 output/os -d int -no-reboot -no-shutdown
cross-compiler:
	sudo apt update
	sudo apt upgrade
	sudo apt install build-essential -y
	sudo apt install bison -y
	sudo apt install flex -y
	sudo apt install libgmp3-dev -y
	sudo apt install libmpc-dev -y
	sudo apt install libmpfr-dev -y
	sudo apt install texinfo -y
	export PREFIX="/usr/local/x86_64elfgcc"
	export TARGET=x86_64-elf
	export PATH="$PREFIX/bin:$PATH"
	mkdir /tmp/src
	cd /tmp/src
	curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz
	tar xf binutils-2.35.1.tar.gz
	mkdir binutils-build
	cd binutils-build
	../binutils-2.35.1/configure --target=$TARGET --enable-interwork --enable-multilib --disable-nls --disable-werror --prefix=$PREFIX 2>&1 | tee configure.log
	sudo make all install 2>&1 | tee make.log
	cd /tmp/src
	curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz
	tar xf gcc-10.2.0.tar.gz
	mkdir gcc-build
	cd gcc-build
	../gcc-10.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --disable-libssp --enable-languages=c++ --without-headers
	sudo make all-gcc
	sudo make all-target-libgcc
	sudo make install-gcc
	sudo make install-target-libgcc