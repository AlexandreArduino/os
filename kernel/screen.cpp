#include "screen.h"
#include "types.h"
#include "IO.h"

unsigned int screen::CursorPosition = 0;

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
        screen::refreshCursorPosition(1);
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
}

void screen::refreshCursorPosition(int value)
{
    screen::CursorPosition += value;
    screen::setCursorPosition(screen::CursorPosition);
}