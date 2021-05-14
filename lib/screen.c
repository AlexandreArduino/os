#include "types.h"

#define RAMSTARTSCREEN 0xB8000
#define SIZESCREEN 4000
#define SCREENLIMIT 0xB8FA0 //RAMSTARTSCREEN + SIZESCREEN

void putchar(uchar c)
{
    uchar *video;
    *video = RAMSTARTSCREEN;
    *video = c;
    uchar *color;
    *color = RAMSTARTSCREEN + 1;
    *color = 0x0e;
}