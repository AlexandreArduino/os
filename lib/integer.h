#ifndef __LIB_INTEGER__H
#define __LIB_INTEGER__H
#include "../kernel/types.h"
namespace lib
{
    namespace integer
    {
        void print(int value, u8 base, unsigned short position, u8 color);
        void print(int value, u8 base, unsigned short x, unsigned short y, u8 color);
        unsigned short length(int value, u8 base);
    };
};
#endif