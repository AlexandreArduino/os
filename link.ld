OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    output/kernel/kernel.o
    output/kernel/screen.o
    output/kernel/IO.o
    output/kernel/log.o
    output/kernel/gdt.o
    output/kernel/idt.o
    output/kernel/lib.o
    output/kernel/int.o
    output/kernel/interrupts.o
    output/kernel/pic.o
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