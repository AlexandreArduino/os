#include "log.h"
#include "gdt.h"
#include "idt.h"
#include "pic.h"
#include "lib.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    GlobalDescriptorTable gdt;
    IDT::Init();
    PIC::reset();
    asm volatile("sti"::);
    while(1);
}