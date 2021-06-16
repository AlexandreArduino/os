#pragma once
#include "kernel.h"
#define GDT_PLACE_IN_MEMORY 0x800
#define GDT_SIZE 0xFF
#define NUMBER_DESCRIPTORS 3
namespace GDT
{
    void init();
    void init_descriptor(u32 base, u32 limite, u8 access, u8 other, struct Descriptor *desc);
    struct Register
    {
        u16 limite;
        u32 base;
    }__attribute__((packed));
    struct Descriptor
    {
        u16 limite_0_15;
        u16 base_0_15;
        u8 base_16_23;
        u8 access;
        u8 limite_16_19:4;
        u8 other:4;
        u8 base_24_31;
    }__attribute__((packed));
    extern Descriptor kgdt[3];
    extern Register kgdtr;
};