#include "../kernel/kernel.h"

void BootProcess::Infos::main()
{
    BootProcess::Infos::kernel();
}

void BootProcess::Infos::KernelLogBootProcess()
{
    kernel::print("[BOOT PROCESS] ", BLUE);
}
