#include "integer.h"
#include "../kernel/kernel.h"

char Dev::Hexadecimal::HexaArray[16] = "0123456789ABCDEF";

void Dev::Integer::print(int value, u8 color)
{
    bool IsNeg = false;
    if(value < 0)
    {
        IsNeg = true;
        value = -value;
    }
    unsigned short length = Dev::Integer::length(value);
    char Buffer[length + 1];
    Buffer[0] = '0';
    char c;
    int count = 0;
    while(value)
    {
        c = value % DECIMAL_BASE;
        c += ASCII_OFFSET;
        Buffer[length - count] = c;
        value = (int)value / DECIMAL_BASE;
        count++;
    }
    if(IsNeg)
        Dev::Screen::putchar('-', color);
    for(int i = 1; i < length + 1;i++)
    {
        Dev::Screen::putchar(Buffer[i], color);
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

void Dev::Integer::println(int value, u8 color)
{
    Dev::Integer::print(value, color);
    Dev::Screen::cursor->AddY(1);
    Dev::Screen::cursor->SetLocation(Dev::Screen::cursor->GetX() - Dev::Screen::cursor->GetX(), Dev::Screen::cursor->GetY());
}

void Dev::Hexadecimal::print(int value, u8 color)
{
    bool IsNeg = false;
    if(value < 0)
    {
        IsNeg = true;
        value = -value;
    }
    unsigned short length = Dev::Hexadecimal::length(value);
    char Buffer[length + 1];
    Buffer[0] = '0';
    u8 c;
    int count = 0;
    while(value)
    {
        c = value % HEXADECIMAL_BASE;
        Buffer[length - count] = Dev::Hexadecimal::HexaArray[c];
        value = (int)value / HEXADECIMAL_BASE;
        count++;
    }
    if(IsNeg)
    {
        Dev::Screen::putchar('-', color);

    }
    Dev::Screen::print("0x", color);
    for(int i = 1; i < length + 1;i++)
    {
        Dev::Screen::putchar(Buffer[i], color);
    }
}

void Dev::Hexadecimal::println(int value, u8 color)
{
    Dev::Hexadecimal::print(value, color);
    Dev::Screen::cursor->AddY(1);
    Dev::Screen::cursor->SetLocation(Dev::Screen::cursor->GetX() - Dev::Screen::cursor->GetX(), Dev::Screen::cursor->GetY());
}

unsigned short Dev::Hexadecimal::length(int value)
{
    int count = 0;
    while(value)
    {
        value = (int)value / HEXADECIMAL_BASE;
        count++;
    }
    return count;
}