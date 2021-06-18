#include "gdt.h"
#include "../kernel/kernel.h"

namespace init
{
    namespace kernel
    {
        __attribute__((aligned(0x1000)));
        GDT DefaultGDT = {
            {0, 0, 0, 0x00, 0x00, 0}, //Null
            {0, 0, 0, 0x9A, 0xA0, 0}, //Kernel code
            {0, 0, 0, 0x92, 0xA0, 0}, //Kernel data
            {0, 0, 0, 0x00, 0x00, 0}, //User null
            {0, 0, 0, 0x9A, 0xA0, 0}, //User code
            {0, 0, 0, 0x92, 0xA0, 0}  //User data
        };
    };
};

void init::kernel::SetGDT()
{
    init::kernel::Descriptor gdtD;
    gdtD.Size = sizeof(init::kernel::GDT) - 1;
    gdtD.Offset = (long long)&init::kernel::DefaultGDT;
    init::kernel::LoadGDT(&gdtD);
}