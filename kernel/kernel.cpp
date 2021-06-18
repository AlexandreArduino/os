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
    print("Kernel loaded at ", LIGHT_PURPLE);
    PrintHex(KERNEL_SPACE, LIGHT_PURPLE);
    println("!", LIGHT_PURPLE);
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
    print("Test of the pow function : 8^8 = ", YELLOW);
    PrintIntLn(lib::math::pow(8, 8), YELLOW);
    PrintIntLn(lib::math::SquareRoot(-5));
    while(1);
}