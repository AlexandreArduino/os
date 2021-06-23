#ifndef __INIT__INTERRUPTS_DESCRIPTOR_TABLE_H
#define __INIT__INTERRUPTS_DESCRIPTOR_TABLE_H
#include "../kernel/kernel.h"
struct IDT64
{
    u16 OffsetLow;
    u16 Selector;
    u8 ist;
    u8 TypesAddr;
    u16 OffsetMid;
    u32 OffsetHigh;
    u32 zero;
};
extern IDT64 _idt[256];
extern long long isr1;
void InitializeIDT();
extern "C" void isr1_handler();
extern "C" void LoadIDT();
#endif