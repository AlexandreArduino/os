#pragma once
#include "types.h"
namespace IO
{
    void outb(unsigned short port, unsigned char value);
    unsigned char inb(unsigned short port);
    void cli();
    void sti();
    void outbWithTemporisation(unsigned short port, unsigned char value);
};