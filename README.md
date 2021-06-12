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

# II) Kernel

The kernel is the brain of the Operating System. Here, it is written in C/C++/ASM. It has do to a lot of things and it main directory in kernel/.

# III) Dev

The dev/ directory is just here to test class, functions in dev.
    
 PS : The readme is not finished!
