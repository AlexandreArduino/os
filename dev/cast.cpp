#include "cast.h"
#include "../kernel/screen/log.h"
#include "../kernel/screen/screen.h"
#include "print.h"

void Dev::Hexadecimal::ToString(int value)
{
    char number = value + 48;
    char *video = (char*)(VIDEO_MEMORY);
    *video = number;
}

void Dev::Integer::ToString(int value)
{
    int length = Dev::Integer::Length(value);
    char Buffer[length];
    int count = 0;
    while(value > 0)
    {
        char c = value % 10;
        c += 48;
        Buffer[length - count] = c;
        value = (int)value / 10;
        count++;
    }
    /*for(int i = length; i > 0;i--)
    {
        screen::Text::putchar(Buffer[i], GREEN, 100 + i*2);
    }*/
    Dev::Print::PrintArray(Buffer, length, 0);
}

int Dev::Integer::Length(int value)
{
    int count = 0;
    while(value > 0)
    {
        count++;
        value = (int)value/10;
    }
    return count;
}