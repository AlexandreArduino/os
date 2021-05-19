OUTPUT_FORMAT(binary)

ENTRY (_start)

INPUT
(
    output/bootloader/ExtendedProgram.o
    output/kernel/kernel.o
)

OUTPUT
(
    output/kernel.bin
)

SECTIONS
{
    . = 0x7e00;
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