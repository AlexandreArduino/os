#include "../kernel/kernel.h"
IDTRegister idtr;
IDTDescriptor idt[IDTSIZE];
void DefaultInterrupt();
void InitDescriptor(u16 selector, u64 offset, u16 typeattr, IDTDescriptor *desc)
{
    desc->offset0_15 = (u16)(offset & 0x000000000000FFFF);
    desc->selector = selector;
    desc->typeattr = typeattr;
    desc->zero = 0;
    desc->ist = 0;
    desc->offset16_32 = (u16)(offset & 0x00000000FFFF0000);
    desc->offset32_64 = (u32)(offset & 0XFFFFFFFF00000000);
}
void InitIDT()
{
    Screen::info("Initializing Interrupts Descriptor Table...");
    pic::init();
    for(int i = 0; i < IDTSIZE; i++)
        InitDescriptor(0x08, (u64)DefaultInterrupt, INTGATE, &idt[i]);
    idtr.base = &idt[0];
    idtr.limit = (u16)sizeof(IDTDescriptor) * IDTSIZE - 1;
    __asm__ volatile("lidt %0" : : "m"(idtr));
    __asm__ volatile("sti");
}
extern "C" void DefaultInterruptHandler()
{
    kernel::println("oui");
}