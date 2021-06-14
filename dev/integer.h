#ifndef __INTEGER_H
#define __INTEGER_H
#include "../kernel/kernel.h"
#define DECIMAL_BASE 10
#define ASCII_OFFSET 48
namespace Dev
{
    namespace Integer
    {
        void print(int value, u8 color);
        void println(int value, u8 color);
        unsigned short length(int value);
    };
};

#endif