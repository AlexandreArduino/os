#ifndef __LIB_INTEGER__H
#define __LIB_INTEGER__H
#include "../kernel/types.h"
namespace lib
{
    /*class Integer
    {
    public:
        Integer(int value, u8 base);
        ~Integer();
        u8 Length();
        void ToString();
        void PrintString(unsigned short position);
    private:
        int _value;
        u8 _base;
        char BufferToString[];
    };*/
    namespace integer
    {
        void print(int value, u8 base, unsigned short position, u8 color);
        unsigned short length(int value, u8 base);
    };
};
#endif