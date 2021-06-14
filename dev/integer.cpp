#include "integer.h"
#include "../kernel/kernel.h"

void Dev::Integer::print(int value)
{
    int length = Dev::Integer::length(value);
    char Buffer[length + 1];
    Buffer[0] = '0';
    char c;
    int count = 0;
    while(value)
    {
        c = value % DECIMAL_BASE;
        c += ASCII_OFFSET;
        Buffer[length - count + 1] = c;
        value = (int)value / DECIMAL_BASE;
        count++;
    }
    for(int i = length + 1; i > 1;i++)
    {
        screen::Text::putchar(Buffer[i], YELLOW, i*2);
    }
}

unsigned short Dev::Integer::length(int value)
{
    int count = 0;
    while(value)
    {
        value = (int)value / DECIMAL_BASE;
        count++;
    }
    return count;
}