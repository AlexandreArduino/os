#pragma once
#include "types.h"
#define IDT_MEMLOC 0x3ff
#define IDT_NUMDESC 0xFF
#define INTGATE 0x8600
namespace IDT
{
    struct Descriptor
    {
        u16 Offset_0_15;
        u16 SegmentSelector;
        u16 Flags;
        u16 Offset_16_31;
    }__attribute__((packed));
    void InitDescriptor(u16 SegmentSelector, u32 Offset, u16 Type, struct Descriptor* descriptor);
    void Init();
    extern struct Descriptor kidt[IDT_NUMDESC];
    struct Register
    {
        u16 limit;
        u32 base;
    }__attribute__((packed));
};

extern struct IDT::Register IdtRegister;