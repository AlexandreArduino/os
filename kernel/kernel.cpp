#include "screen.h"

using namespace screen;

extern "C" void _start()
{
    clear();
    print("Hi, this is my print function! :p", YELLOW, 0);
    while(1);
}