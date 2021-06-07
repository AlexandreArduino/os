#include "integer.h"
#include "../kernel/screen/log.h"
#include "../kernel/types.h"
#include "../kernel/screen/screen.h"
/*lib::Integer::Integer(int value, u8 base)
{
    _value = value;
    _base = base;
    screen::log::print("New integer variable created!");
}

lib::Integer::~Integer(){}

u8 lib::Integer::Length()
{
    int __value = _value;
    int count = 0;
    while(__value > 0)
    {
        count++;
        __value = (int)__value / _base;
    }
}

void lib::Integer::ToString()
{
    int length = lib::Integer::Length();
    lib::Integer::BufferToString[length];
    int count = 0;
    int __value = _value;
    while(__value > 0)
    {
        char c = __value % _base;
        c += 48;
        lib::Integer::BufferToString[length - count] = c;
        __value = (int)__value / 10;
        count++;
    }
}

void lib::Integer::PrintString(unsigned short position)
{
    screen::Text::PrintArrayReversedWithoutNullTerminated(lib::Integer::BufferToString, lib::Integer::Length(), position);
}*/

void lib::integer::print(int value, u8 base, unsigned short position, u8 color)
{
    screen::log::print("Printing integer value ...");
    int length = lib::integer::length(value, base);
    char Buffer[length + 1];
    Buffer[0] = '0';
    screen::log::print("Setting buffer ...");
    char c;
    int count = 0;
    if(position % 2)
        position++;
    while(value)
    {
        c = value % base;
        c += 48;
        Buffer[length - count + 1] = c;
        value = (int)value / base;
        count++;
    }
    for(int i = length + 1; i > 1;i--)
    {
        screen::Text::putchar(Buffer[i], color, position + i*2 - 4);
    }
}

unsigned short lib::integer::length(int value, u8 base)
{
    screen::log::print("Getting length of integer ...");
    int count = 0;
    while(value)
    {
        value /= base;
        count++;
    }
    return count;
}