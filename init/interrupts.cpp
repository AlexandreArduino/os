#include "../kernel/kernel.h"
extern IDT64 _idt[256];
extern unsigned long long isr1;
extern "C" void isr1_handler();
extern "C" void LoadIDT();

void InitializeIDT()
{
    Screen::info("Setting up Interrupts Descriptor Table...");
    for(unsigned long long t = 0; t < 256; t++)
    {
        _idt[t].zero = 0;
        _idt[t].OffsetLow = (u16)(((unsigned long long)&isr1 & 0x000000000000ffff));
        _idt[t].OffsetMid = (u16)(((unsigned long long)&isr1 & 0x00000000ffff0000) >> 16);
        _idt[t].OffsetHigh = (u32)(((unsigned long long)&isr1 & 0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].Selector = 0x08;
        _idt[t].TypesAddr = 0x8E;
    }
    IO::outb(0x21, 0xfd);
    IO::outb(0xa1, 0xff);
    LoadIDT();
    Screen::success("Interrupts Descriptor Table loaded successfully!");
}

extern "C" void isr1_handler()
{
    // kernel::println("Une touche a été pressée!");
    IO::outb(0x20, 0x20);
    IO::outb(0xa0, 0x20);
}