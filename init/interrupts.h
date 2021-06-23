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
}__attribute__((packed));

void InitializeIDT();

#endif