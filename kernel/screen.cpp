#include "screen.h"
#include "types.h"
void screen::clear()
{
    char *video;
    for(unsigned int i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
}

void screen::putchar(char c, u16 color, u16 position)
{
    if(position < SIZE_SCREEN && position >= 0)
    {
        char *video = VIDEO_MEMORY + (char*)(position*2);
        *video = c;
        char *colour = VIDEO_MEMORY + (char*)(position*2+1);
        *colour = color;
    }
    else{}
}

void screen::print(char *str, u16 color, u16 position)
{
    u8 count = 0;
    while(*str != 0)
    {
        putchar(*str, color, position + count);
        count += 1;
        str++;
    }
}