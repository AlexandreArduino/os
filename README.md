# os
I'm trying to develop my own Operating System 64 bits because it is fun :p

# I) Bootloader

You can find it in bootloader/. It has to :

    - set up the data register and the stack in real mode (4kb)
    - load the gdt (and create it)
    - enable A20 (idk what it is yet)
    - set up the CPU in protected mode
    - reload data segments
    - detect CPUID to have informations about the CPU
    - detect if long mode (64 bits) is available on the CPU
    - enable paging
    - set up the CPU in long mode
    - load the main function of the kernel

Note

    Program Space equ ExtendedProgram

Memory segmentation from first sector to end of the Kernel space : 

    0x7C00 - 0x7E00 - 0x8600 -    0x95A0   - 

    -----------------------------------------------------
    |           |            |              |
    |           |            |              |
    |    512    |    2048    |     4000     |
    |   bytes   |    bytes   |     bytes    |
    |           |            |              |
    |           |            |              |
    -----------------------------------------------------

    Minimal boot   Program        Stack         Kernel
       loader       Space                       Space