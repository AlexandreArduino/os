#include "screen.h"

void screen::clear()
{
    char *video;
    for(unsigned int i = 0; i < SIZE_SCREEN*2; i+=2)
    {
        video = VIDEO_MEMORY + (char*)i;
        *video = ' ';
    }
}