#include "IO.h"

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