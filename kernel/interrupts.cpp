#include "interrupts.h"
#include "kernel.h"

/*IDT::Register *kidtr;

namespace IDT
{
    void init::Descriptor(u16 selector, u32 offset, u16 TypeAttr, struct Descriptor *desc)
    {
        desc->offset0 = (offset & 0xFFFF);
        desc->selector = selector;
        desc->TypeAttr = TypeAttr;
        desc->offset1 = (offset & 0xFFFF0000) >> 16;
    }

    void init::IDT()
    {
        kernel::println("Setting IDT ...");
    }
};*/