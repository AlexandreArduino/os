#include "screen.h"
#include "log.h"

extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    screen::log::print("Cursor set!");
    while(1);
}