# os
I'm trying to develop my own Operating System 32 bits because my computer has only 4GB of RAM

# I) Bootloader

You can find it in bootloader/. It has to :

    - set up the data register and the stack in real mode
    - load the gdt (and create it)
    - enable A20 (idk what it is for now)
    - set up the CPU in protected mode
    - reload data segments
    - detect CPUID to have informations about the CPU
    - detect if long mode (64 bits) is available on the CPU
    - enable paging