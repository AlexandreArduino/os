#include "screen.h"
#include "log.h"
#include "gdt.h"
extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    GlobalDescriptorTable gdt;
    while(1);
}