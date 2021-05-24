#include "screen.h"

using namespace screen;

extern "C" void _start()
{
    clear();
    char *str = "Hello World!";
    u8 count = 0;
    for(u8 i = 0; i < 10;i++)
    {
    	putchar(str[i], PURPLE, i);
    }
    while(1);
}