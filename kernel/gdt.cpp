#include "kernel.h"
namespace GDT
{
    void init()
    {
        kernel::println("Setting up the GDT ...");
        kernel::cli();
        
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