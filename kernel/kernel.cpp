#include "screen/log.h"
#include "../lib/integer.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
using namespace lib;
extern "C" void _start()
{
    screen::clear();
    screen::exceptions::success("Kernel loaded at 0x8600!");
    screen::log::print("Loading the whole kernel ...");
    screen::log::print("---------------------------------------");
    screen::log::print("Text at line 4 before scrolling the screen!");
    screen::Text::scroll(2);
    screen::log::print("Text at line 3 after scrolling the screen!");
    screen::Integer::PrintInt(123456, 10, 126, CYAN);
    screen::log::print("The kernel is able to print integers by converting them!");
    while(1);
}