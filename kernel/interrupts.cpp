#include "types.h"
#include "log.h"

extern "C" void isr_default_int()
{
    screen::log::print("Interrupt!");
}

extern "C" void isr_clock_int()
{
    static int tic, sec = 0;
    tic++;
    if(!(tic % 100))
        sec++;
        tic = 0;
        screen::log::print("Clock!");
}

extern "C" void isr_kbd_int()
{
    screen::log::print("Keyboard!");
}