#include "screen.h"
#include "types.h"
#include "IO.h"

/*unsigned int screen::CursorPosition = 0;
unsigned int screen::CursorLinePosition = 0;

void screen::init()
{
    //screen::CursorPosition = 0;
    screen::setCursorPosition(screen::CursorPosition);
}

void screen::clear()
{
    char *video;
    for(unsigned int i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
    screen::CursorPosition = 0;
    screen::setCursorPosition(screen::CursorPosition);
}

void screen::putchar(char c, u16 color, u16 position)
{
    if(position < SIZE_SCREEN && position >= 0)
    {
        char *video = VIDEO_MEMORY + (char*)(position*2);
        *video = c;
        char *colour = VIDEO_MEMORY + (char*)(position*2+1);
        *colour = color;
        screen::CursorPosition = position + 1;
        screen::setCursorPosition(screen::CursorPosition);
    }
    else{}
}

void screen::print(char *str, u16 color, u16 position, u16 _line)
{
    u8 count = LENGTH_LINE*_line;
    while(*str != 0)
    {
        putchar(*str, color, position + count);
        count += 1;
        str++;
    }
}

void screen::setCursorPosition(unsigned short position)
{
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(position & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((position >> 8) & 0xFF));
}*/

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

void screen::Dev::putcharWithoutCursor(char c, unsigned short color, unsigned short position)
{
    char *video = (char*)(VIDEO_MEMORY + position);
    *video = c;
    char *colour = (char*)(VIDEO_MEMORY + position + 1);
    *colour = color;
}

void screen::Dev::PrintWithoutCursor(char *str, unsigned short color, unsigned short StartPosition)
{
    u8 count = 0;
    while(*str != 0)
    {
        screen::Dev::putcharWithoutCursor(*str, color, StartPosition + count);
        count += 1;
        str++;
    }
}