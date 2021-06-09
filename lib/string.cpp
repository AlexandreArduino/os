#include "../kernel/kernel.h"

u8 lib::string::Length(char *str)
{
    int count = 0;
    while(*str != 0)
    {
        count++;
        str++;
    }
    return count;
}