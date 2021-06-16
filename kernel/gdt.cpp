#include "kernel.h"

namespace GDT
{
    Descriptor kgdt[3];
    Register kgdtr;
    void init()
    {
        kernel::println("Setting up the GDT ...");
        kernel::cli();
        init_descriptor(0x0, 0x0, 0x0, 0x0, &kgdt[0]);          /* NULL */
        init_descriptor(0x0, 0xFFFFF, 0x9B, 0x0D, &kgdt[1]);    /* code */
        init_descriptor(0x0, 0xFFFFF, 0x93, 0x0D, &kgdt[2]);    /* data */
        kgdtr.limite = GDT_SIZE * NUMBER_DESCRIPTORS;
        kgdtr.base = GDT_PLACE_IN_MEMORY;
        kernel::memcpy(kgdtr.base, &kgdtr, kgdtr.limite);
        __asm__ __volatile__("lgdt %0":: "m"(kgdtr));
    }

    void init_descriptor(u32 base, u32 limite, u8 access, u8 other, struct Descriptor *desc)
    {
        kernel::println("Setting up descriptor ...");
        desc->limite_0_15 = (limite & 0xFFFF);
        desc->base_0_15 = (base & 0xFFFF);
        desc->base_16_23 = (base & 0xff0000) >> 16;
        desc->access = access;
        desc->limite_16_19 = (limite & 0xf0000) >> 16;
        desc->other = (other & 0xf);
        desc->base_24_31 = (base & 0xff000000) >> 24;
        return;
    }
};