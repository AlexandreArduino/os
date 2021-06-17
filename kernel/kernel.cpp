#include "kernel.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
void *__cxa_atexit;
void *__dso_handle;
using namespace kernel;
extern "C" void _start()
{
    TextCursor MainTextCursor(0);
    Screen::init(MainTextCursor);
    clear();
    print("Kernel loaded at ", BLUE);
    PrintHex(KERNEL_SPACE, BLUE);
    println("!", BLUE);
    print("Bootloader loaded from ");
    PrintHex(BOOTLOADER_SPACE);
    print(" to ");
    PrintHex(BOOTLOADER_EXTENDED_SPACE);
    println("!");
    print("Top of the stack at ");
    PrintHex(TOP_STACK);
    println("!");
    print("Bottom of the stack at ");
    PrintHex(BOTTOM_STACK);
    println("!");
    PrintIntLn(lib::math::pow(5, 10), GREEN);
    while(1);
}