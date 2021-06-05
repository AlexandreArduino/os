#include "IO.h"
#include "../types.h"
void IO::outb(unsigned short port, unsigned char value)
{
    asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));   
}

unsigned char IO::inb(unsigned short port)
{
    unsigned char Value;
    asm volatile ("inb %1, %0" : "=a"(Value) : "Nd"(port));
    return Value;
}

void IO::cli()
{
    asm("cli"::);
}

void IO::sti()
{
    asm("sti"::);
}

void IO::outbWithTemporisation(unsigned short port, unsigned char value)
{
    asm volatile ("outb %%al, %%dx; jmp 1f; 1:" :: "d" (port), "a" (value));
}