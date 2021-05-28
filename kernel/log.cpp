#include "log.h"
#include "types.h"
#include "screen.h"

unsigned short screen::log::y = 0;

void screen::log::print(char *str)
{
    if(LOG)
    {
        screen::Text::print("[LOG] => ", GREEN, 0, screen::log::y);
        screen::Text::print(str, LOG_COLOR, 9, screen::log::y);
        screen::log::y++;
        if(y > HEIGHT_SIZE){y = HEIGHT_SIZE;}
    }else{}
}