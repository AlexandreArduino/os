#include "screen.h"

extern "C" void _start()
{
    screen::clear();
    screen::Text::print("Kernel loaded !", GREEN, 0, 0);
    while(1);
}