#include "idt.h"
#include "types.h"
#include "log.h"
#include "lib.h"
extern "C" void _asm_default_int();
extern "C" void _asm_irq_0();
extern "C" void _asm_irq_1();

struct IDT::Descriptor IDT::kidt[IDT_NUMDESC];
struct IDT::Register IdtRegister;

void IDT::InitDescriptor(u16 Selector, u32 Offset, u16 Type, struct Descriptor* descriptor)
{
    descriptor->SegmentSelector = Selector;
    descriptor->Offset_0_15 = (Offset & 0xFFFF);
    descriptor->Offset_16_31 = (Offset & 0xFFFF0000);
    descriptor->Flags = Type;
}
void *memcpy(char *dst, char *src, int n)
{
	char *p = dst;
	while (n--)
		*dst++ = *src++;
	return p;
}
void IDT::Init()
{
    screen::log::print("Initializing IDT ...");
    screen::log::print("Kernel defaults descriptors ...");
    for(int i = 0; i < IDT_NUMDESC;i++)
        IDT::InitDescriptor(0x08, (u32)_asm_default_int, INTGATE, &IDT::kidt[i]);
    screen::log::print("Clock descriptor ...");
    IDT::InitDescriptor(0x08, (u32)_asm_irq_0, INTGATE, &kidt[32]);
    screen::log::print("Keyboard descriptor ...");
    IDT::InitDescriptor(0x08, (u32)_asm_irq_1, INTGATE, &kidt[33]);
    screen::exceptions::success("Kernel descriptors created!");
    screen::log::print("Creating IDT register ...");
    IdtRegister.limit = IDT_NUMDESC * 8;
    IdtRegister.base = IDT_MEMLOC;
    screen::log::print("Loading IDT register in memory ...");
    memcpy((char*)IdtRegister.base, (char*)IDT::kidt, IdtRegister.limit);
    asm("lidt (IdtRegister)");
}