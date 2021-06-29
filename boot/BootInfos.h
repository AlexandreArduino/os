#ifndef __BOOTINFOS_KERNEL_H
#define __BOOTINFOS_KERNEL_H

namespace BootProcess
{
    namespace Infos
    {
        void kernel();
        void StartInitPic();
        void EndInitPic();
        void main();
        void KernelLogBootProcess();
    };
};

#endif