#include "kernel.h"
#include "../kernel/kernel.h"
using namespace kernel;
void init::kernel::PrintAtBoot()
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
}

void init::kernel::DecideTest()
{
    if(TEST_ON_BOOT)
        test();
}

void init::kernel::main()
{
    init::kernel::PrintAtBoot();
    init::kernel::DecideTest();
}