#pragma once
#include "kernel.h"
/*#define IDTBASE 0x00000000
#define IDTSIZE 0xFF
namespace IDT
{
    struct Register
    {
        u16 limite;
        u32 base;
    }__attribute__((packed));
    struct Descriptor
    {
        u16 offset0;
        u16 selector;
        u16 TypeAttr;
        u16 offset1;
    }__attribute__((packed));
    namespace init
    {
        void Descriptor(u16 selector, u32 offset, u16 TypeAttr, struct Descriptor* desc);
        void IDT();
    };
    extern Register* kidtr;
};*/

namespace IDT
{
    struct Entry
    {
        unsigned short LowBase;
        unsigned short Sel;
        unsigned char AlwaysZero;
        unsigned char Flags;
        unsigned short HighBase;
    }__attribute__((packed));
    struct Ptr
    {
        unsigned short Limite;
        unsigned int Base;
    }__attribute__((packed));
    extern struct Entry idt[256];
    extern struct Ptr idtp;
    void init();
    extern void idt_load();
};