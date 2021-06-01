#include "screen.h"
#include "types.h"
#include "IO.h"

unsigned short screen::TextCursor::x = 0;
unsigned short screen::TextCursor::y = 0;

void screen::clear()
{
    char *video;
    for(unsigned short i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
    screen::TextCursor::Refresh(0, 0);
}

unsigned short screen::TextCursor::GetLocation(unsigned short x, unsigned short y)
{
    if(screen::TextCursor::x != x)  screen::TextCursor::x = x;
    if(screen::TextCursor::y != y)  screen::TextCursor::y = y;
    return x + y * LENGTH_LINE;
}

void screen::TextCursor::SetPosition(unsigned short position)
{
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(position & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}

void screen::TextCursor::Refresh(unsigned short x, unsigned short y)
{
    screen::TextCursor::SetPosition(screen::TextCursor::GetLocation(x, y));
}

void screen::Text::putchar(char c, unsigned short color, unsigned short x, unsigned short y)
{
    char *video = (char*)(VIDEO_MEMORY + screen::Text::GetLocation(x*2, y));
    *video = c;
    char *colour = (char*)(VIDEO_MEMORY + screen::Text::GetLocation(x*2, y) + 1);
    *colour = color;
    screen::TextCursor::SetPosition((int)screen::Text::GetLocation(x*2, y)/2 + 1);
}

void screen::Text::putchar(char c, unsigned short color, unsigned short position)
{
    char *video = (char*)(VIDEO_MEMORY + position);
    *video = c;
    char *colour = (char*)(VIDEO_MEMORY + position + 1);
    *colour = color;
    screen::TextCursor::SetPosition((int)position/2 + 1);
}

unsigned short screen::Text::GetLocation(unsigned short x, unsigned short y)
{
    return x + y * LENGTH_LINE;
}

inline void screen::TextCursor::AddValueCursor(unsigned short value)
{
    screen::TextCursor::Refresh(screen::TextCursor::x + value, screen::TextCursor::y);
}

void screen::Text::print(char *str, unsigned short color, unsigned short position)
{
    unsigned short count = 0;
    while(*str != 0)
    {
        screen::Text::putchar(*str, color, position + count);
        count += 2;
        str++;
    }
}

void screen::Text::print(char *str, unsigned short color, unsigned short x, unsigned short y)
{
    unsigned short count = 0;
    while(*str != 0)
    {
        screen::Text::putchar(*str, color, x + count, y*2);
        count++;
        str++;
    }
}