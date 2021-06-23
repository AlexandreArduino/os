OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    output/kernel/kernel.o
    output/kernel/screen/screen.o
    output/kernel/hardware/IO.o
    output/lib/integer.o
    output/lib/math.o
    output/lib/string.o
    output/kernel/utils.o
    output/kernel/screen/TextCursor.o
    output/lib/string.o
    output/test/math.o
    output/lib/float.o
    output/test/screen.o
    output/init/gdt.o
    output/init/gdt_asm.o
    output/boot/BootInfos.o
    output/boot/kernel.o
    output/init/interrupts.o
    output/init/interruptsasm.o
)

OUTPUT
(
    output/ckernel
)

SECTIONS
{
    . = 0x8600;

    .text : ALIGN(0x1000)
    {
        *(.text)
    }

    .idt BLOCK(0x1000) : ALIGN(0x1000)
    {
        _idt = .;
        . = . + 0x1000;
    }

    .data : ALIGN(0x1000)
    {
        *(.data)
    }

    .rodata : ALIGN(0x1000)
    {
        *(.rodata)
    }

    .bss : ALIGN(0x1000)
    {
    *(COMMON)
    *(.bss)
    }
}