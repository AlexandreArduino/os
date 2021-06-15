#include "kernel.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
void *__cxa_atexit;
void *__dso_handle;
using namespace kernel;
extern "C" void _start()
{
    /*TextCursor MainTextCursor(0);
    Screen::init(MainTextCursor);
    Screen::clear();
    print("Kernel loaded at ");
    PrintHex(KERNEL_SPACE);
    println("!");*/
    clear();
    print("Kernel loaded at ");
    PrintHex(KERNEL_SPACE);
    println("!");
    while(1);
}