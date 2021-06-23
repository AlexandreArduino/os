#include "../kernel/kernel.h"

void BootProcess::Infos::kernel()
{
    BootProcess::Infos::KernelLogBootProcess();
    kernel::print("Bootloader loaded from ");
    kernel::PrintHex(BOOTLOADER_SPACE);
    kernel::print(" to ");
    kernel::PrintHex(BOOTLOADER_EXTENDED_SPACE);
    kernel::println("!");
    BootProcess::Infos::KernelLogBootProcess();
    kernel::print("Kernel loaded at ");
    kernel::PrintHex(KERNEL_SPACE);
    kernel::println("!");
    BootProcess::Infos::KernelLogBootProcess();
    kernel::print("Top of the stack : ");
    kernel::PrintHex(TOP_STACK);
    kernel::println("!");
    BootProcess::Infos::KernelLogBootProcess();
    kernel::print("Bottom of the stack : ");
    kernel::PrintHex(BOTTOM_STACK);
    kernel::println("!");
}