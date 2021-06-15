#pragma once
#include "../kernel/kernel.h"
#define DECIMAL_BASE 10
#define HEXADECIMAL_BASE 16
#define ASCII_OFFSET 48
 
namespace Integer
{
    void print(int value, u8 color);
    void println(int value, u8 color);
    unsigned short length(int value);
};

namespace Hexadecimal
{
    extern char HexaArray[16];
    void print(int value, u8 color);
    void println(int value, u8 color);
    unsigned short length(int value);
};