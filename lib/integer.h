#ifndef __LIB_INTEGER__H
#define __LIB_INTEGER__H
#include "../kernel/kernel.h"
namespace lib
{
    namespace integer
    {
        void print(int value, unsigned short position, u8 color);
        void print(int value, unsigned short x, unsigned short y, u8 color);
        void println(int value, unsigned short position, u8 color);
        void println(int value, unsigned short x, unsigned short y, u8 color);
        unsigned short length(int value);
    };
    namespace hexadecimal
    {
        unsigned short length(int value);
    };
};
#endif