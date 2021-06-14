#include "screen.h"
#include "../kernel/kernel.h"

/*
* To access to cursor object : Dev::Screen::cursor->function;
*/

TextCursor *Dev::Screen::cursor;

void Dev::Screen::init(TextCursor _cursor)
{
    Dev::Screen::cursor = &_cursor;
}
void Dev::Screen::putchar(char c, unsigned int position, u8 color)
{
    char *video = (char*)(VIDEO_MEMORY + position*2);
    *video = c;
    video++;
    *video = color;
    Dev::Screen::cursor->SetLocation(position + 1);
}

void Dev::Screen::putchar(char c, u8 color)
{
    Dev::Screen::putchar(c, cursor->GetLocation(), color);
}

void Dev::Screen::print(char *str, u8 color)
{
    while(*str != 0)
    {
        putchar(*str, color);
        str++;
    }
}
void Dev::Screen::println(char *str, u8 color)
{
    while(*str != 0)
    {
        putchar(*str, color);
        str++;
    }
    cursor->AddY(1);
    cursor->SetLocation(cursor->GetX() - cursor->GetX(), cursor->GetY());
}

void Dev::Screen::print(char *str, unsigned int position, u8 color)
{
    unsigned int count = 0;
    while(*str != 0)
    {
        putchar(*str, position + count, color);
        str++;
        count++;
    }
}

void Dev::Screen::println(char *str, unsigned int position, u8 color)
{
    Dev::Screen::print(str, position, color);
    cursor->AddY(1);
    cursor->SetLocation(cursor->GetX() - cursor->GetX(), cursor->GetY());
}

void Dev::Screen::scroll(u8 NumberLines)
{
    int last_y = cursor->GetY();
    int last_x = cursor->GetX();
    char *current;
    char *destination;
    int i;
    for(i = 0; i < SIZE_SCREEN - NumberLines*LENGTH_LINE;i++)
    {
        current = (char*)(VIDEO_MEMORY + LENGTH_LINE*NumberLines*2 + i);
        destination = (char*)(VIDEO_MEMORY + i);
        *destination = *current;
    }
    cursor->SetLocation(last_x, last_y - NumberLines);
}

void Dev::Screen::clear()
{
    char *video;
    for(unsigned short i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
    cursor->SetLocation(0);
}