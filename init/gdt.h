#ifndef __INIT__GLOBAL_DESCRIPTOR_TABLE_H
#define __INIT__GLOBAL_DESCRIPTOR_TABLE_H
#include "../kernel/kernel.h"
namespace init
{
    namespace kernel
    {
        struct Descriptor
        {
            u16 Size;
            long long Offset;
        }__attribute__((packed));

        struct Entry
        {
            u16 Limit0;
            u16 Base0;
            u8 Base1;
            u8 AccessByte;
            u8 Limit1_and_Flags;
            u8 Base2;
        }__attribute__((packed));

        struct GDT
        {
            Entry Null; //0x00
            Entry KernelCode; //0x08
            Entry KernelData; //0x10
            Entry UserNull;
            Entry Usercode;
            Entry UserData;
        }__attribute__((packed))
        __attribute__((aligned(0x1000)));

        extern GDT DefaultGDT;
        extern "C" void LoadGDT(Descriptor *gdtDescriptor);
        void SetGDT();
    };
};

#endif