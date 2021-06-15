#include "integer.h"
#include "../kernel/kernel.h"

char Hexadecimal::HexaArray[16] = "0123456789ABCDEF";

void Integer::print(int value, u8 color)
{
    bool IsNeg = false;
    if(value < 0)
    {
        IsNeg = true;
        value = -value;
    }
    unsigned short length = Integer::length(value);
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
        Screen::putchar('-', color);
    for(int i = 1; i < length + 1;i++)
    {
        Screen::putchar(Buffer[i], color);
    }
}

unsigned short Integer::length(int value)
{
    int count = 0;
    while(value)
    {
        value = (int)value / DECIMAL_BASE;
        count++;
    }
    return count;
}

void Integer::println(int value, u8 color)
{
    Integer::print(value, color);
    Screen::cursor->AddY(1);
    Screen::cursor->SetLocation(Screen::cursor->GetX() - Screen::cursor->GetX(), Screen::cursor->GetY());
}

void Hexadecimal::print(int value, u8 color)
{
    bool IsNeg = false;
    if(value < 0)
    {
        IsNeg = true;
        value = -value;
    }
    unsigned short length = Hexadecimal::length(value);
    char Buffer[length + 1];
    Buffer[0] = '0';
    u8 c;
    int count = 0;
    while(value)
    {
        c = value % HEXADECIMAL_BASE;
        Buffer[length - count] = Hexadecimal::HexaArray[c];
        value = (int)value / HEXADECIMAL_BASE;
        count++;
    }
    if(IsNeg)
    {
        Screen::putchar('-', color);

    }
    Screen::print("0x", color);
    for(int i = 1; i < length + 1;i++)
    {
        Screen::putchar(Buffer[i], color);
    }
}

void Hexadecimal::println(int value, u8 color)
{
    Hexadecimal::print(value, color);
    Screen::cursor->AddY(1);
    Screen::cursor->SetLocation(Screen::cursor->GetX() - Screen::cursor->GetX(), Screen::cursor->GetY());
}

unsigned short Hexadecimal::length(int value)
{
    int count = 0;
    while(value)
    {
        value = (int)value / HEXADECIMAL_BASE;
        count++;
    }
    return count;
}