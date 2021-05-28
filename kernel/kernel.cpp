#include "screen.h"

extern "C" void _start()
{
    screen::clear();
    /*screen::Text::putchar('H', YELLOW, 0,0);
    screen::Text::putchar('H', GREEN, 25, 14);*/
    screen::Dev::PrintWithoutCursor("Hello", PURPLE, 0);
    while(1);
}