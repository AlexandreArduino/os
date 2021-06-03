#include "log.h"
#include "lib.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    string string("Hi");
    string.length();
    while(1);
}