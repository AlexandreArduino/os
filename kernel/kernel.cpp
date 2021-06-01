#include "screen.h"
#include "log.h"
#include "gdt.h"
#include "idt.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
extern "C" void _start()
{
    screen::clear();
    screen::log::print("Kernel loaded!");
    GlobalDescriptorTable gdt;
    init_desc();
    while(1);
}