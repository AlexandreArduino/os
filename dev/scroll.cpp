#include "scroll.h"
#include "../kernel/screen/screen.h"

void Dev::scroll::SaveLineBuffer(char *buffer)
{
    *buffer = 'L';
    char *video = (char*)(VIDEO_MEMORY);
    *video = *buffer;
    video++;
    *video = YELLOW;
}