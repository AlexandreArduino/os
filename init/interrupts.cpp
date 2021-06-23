#include "../kernel/kernel.h"

void InitializeIDT()
{
    for(long long t = 0; t < 256; t++)
    {
        _idt[t].zero = 0;
        _idt[t].OffsetLow = (u16)(((long long)&isr1 & 0x000000000000ffff));
        _idt[t].OffsetMid = (u16)(((long long)&isr1 & 0x00000000ffff0000) >> 16);
        _idt[t].OffsetHigh = (u32)(((long long)&isr1 & 0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].Selector = 0x03;
        _idt[t].TypesAddr = 0x8E;
    }
    IO::outb(0x21, 0xfd);
    IO::outb(0xa1, 0xff);
    LoadIDT();
}

extern "C" void isr1_handler()
{
    // kernel::println("Une touche a été pressée!");
    IO::outb(0x20, 0x20);
    IO::outb(0xa0, 0x20);
}