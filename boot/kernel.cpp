#include "../kernel/kernel.h"

void BootProcess::Infos::kernel()
{
    Screen::infowln("Bootloader loaded from ");
    kernel::PrintHex(BOOTLOADER_SPACE);
    kernel::print(" to ");
    kernel::PrintHex(BOOTLOADER_EXTENDED_SPACE);
    kernel::println("!");
    Screen::infowln("Kernel loaded at ");
    kernel::PrintHex(KERNEL_SPACE);
    kernel::println("!");
    Screen::infowln("Top of the stack : ");
    kernel::PrintHex(TOP_STACK);
    kernel::println("!");
    Screen::infowln("Bottom of the stack : ");
    kernel::PrintHex(BOTTOM_STACK);
    kernel::println("!");
}

void BootProcess::Infos::StartInitPic()
{
    BootProcess::Infos::KernelLogBootProcess();
    kernel::println("Initializing PIC...");
}

void BootProcess::Infos::EndInitPic()
{
    Screen::success("PIC initialized successfully!");
}