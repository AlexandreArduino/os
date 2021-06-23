#ifndef __INIT__INTERRUPTS_DESCRIPTOR_TABLE_H
#define __INIT__INTERRUPTS_DESCRIPTOR_TABLE_H
#define IDTSIZE 0xFF
#define INTGATE 0x8E00
#include "../kernel/kernel.h"
struct IDTDescriptor
{
    u16 offset0_15;
    u16 selector;
    u8 ist;
    u8 typeattr;
    u16 offset16_32;
    u32 offset32_64;
    u32 zero;
}__attribute__((packed));
struct IDTRegister
{
    u16 limit;
    u64 base;
}__attribute__((packed));
extern IDTRegister idtr;
extern IDTDescriptor idt[IDTSIZE];
void InitDescriptor(u16 selector, u64 offset, u16 typeattr, IDTDescriptor *desc);
void InitIDT();
extern "C" void DefaultInterrupt();
#endif