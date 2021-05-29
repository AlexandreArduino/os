#include "screen.h"
#include "log.h"

extern void SetSize();

extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    screen::log::print("Cursor set!");
    screen::exceptions::error("Unable to found video driver!");
    screen::exceptions::success("Driver memory found!");
    while(1);
}