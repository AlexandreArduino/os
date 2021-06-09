#include "../kernel/kernel.h"

void lib::integer::print(int value, unsigned short position, u8 color)
{
    // screen::log::print("Printing integer value ...");
    int length = lib::integer::length(value);
    char Buffer[length + 1];
    Buffer[0] = '0';
    // screen::log::print("Setting buffer ...");
    char c;
    int count = 0;
    if(position % 2)
        position++;
    while(value)
    {
        c = value % DEC_BASE;
        c += 48;
        Buffer[length - count + 1] = c;
        value = (int)value / DEC_BASE;
        count++;
    }
    for(int i = length + 1; i > 1;i--)
    {
        screen::Text::putchar(Buffer[i], color, position + i*2 - 4);
    }
    // screen::TextCursor::SetPosition(position + length);
}

void lib::integer::print(int value, unsigned short x, unsigned short y, u8 color)
{
    lib::integer::print(value, screen::TextCursor::GetLocation(x, y), color);
}

unsigned short lib::integer::length(int value)
{
    // screen::log::print("Getting length of integer ...");
    int count = 0;
    while(value)
    {
        value /= DEC_BASE;
        count++;
    }
    return count;
}

void lib::integer::println(int value, unsigned short position, u8 color)
{
    
}

void lib::integer::println(int value, unsigned short x, unsigned short y, u8 color)
{

}


unsigned short lib::hexadecimal::length(int value)
{
    unsigned short count = 0;
    while(value > 0)
    {
        value = (int)value / HEXA_BASE;
        count++;
    }
    return count;
}