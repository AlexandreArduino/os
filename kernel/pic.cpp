#include "pic.h"
#include "IO.h"
#include "log.h"

void PIC::reset()
{
    screen::log::print("Reseting PIC ...");
    IO::outb(0x20, 0x11);
    IO::outb(0xA0, 0x11);
    IO::outb(0x21, 0x20);
    IO::outb(0xA1, 0x70);
    IO::outb(0x21, 0x04);
    IO::outb(0xA1, 0x02);
    IO::outb(0x21, 0x01);
    IO::outb(0xA1, 0x01);
    IO::outb(0x21, 0x0);
    IO::outb(0xA1, 0x0);
    screen::exceptions::success("PIC set!");
}