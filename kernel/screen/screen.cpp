#include "../kernel.h"
#include "TextCursor.h"
//#include "screen.h"
/*
* To access to cursor object : Screen::cursor->function;
*/

TextCursor *Screen::cursor;

void Screen::init(TextCursor _cursor)
{
    Screen::cursor = &_cursor;
}
void Screen::putchar(char c, unsigned int position, u8 color)
{
    char *video = (char*)(VIDEO_MEMORY + position*2);
    *video = c;
    video++;
    *video = color;
    Screen::cursor->SetLocation(position + 1);
}

void Screen::putchar(char c, u8 color)
{
    Screen::putchar(c, cursor->GetLocation(), color);
}

void Screen::print(char *str, u8 color)
{
    while(*str != 0)
    {
        Screen::putchar(*str, color);
        str++;
    }
}
void Screen::println(char *str, u8 color)
{
    while(*str != 0)
    {
        Screen::putchar(*str, color);
        str++;
    }
    cursor->AddY(1);
    cursor->SetLocation(cursor->GetX() - cursor->GetX(), cursor->GetY());
}

void Screen::print(char *str, unsigned int position, u8 color)
{
    unsigned int count = 0;
    while(*str != 0)
    {
        Screen::putchar(*str, position + count, color);
        str++;
        count++;
    }
}

void Screen::println(char *str, unsigned int position, u8 color)
{
    Screen::print(str, position, color);
    cursor->AddY(1);
    cursor->SetLocation(cursor->GetX() - cursor->GetX(), cursor->GetY());
}

void Screen::scroll(u8 NumberLines)
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
    cursor->SetLocation(cursor->GetX(), cursor->GetY() - NumberLines);
}

void Screen::clear()
{
    char *video;
    for(unsigned short i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
    cursor->SetLocation(0);
}
