#include "log.h"
#include "../types.h"
#include "screen.h"
unsigned short screen::log::y = 0;

void screen::log::print(char *str)
{
    if(LOG)
    {
        if(screen::log::y > HEIGHT_SIZE){/*scroll one line*/}else{}
        screen::Text::print("[LOG] ", GRAY, 0, screen::log::y);
        screen::Text::print(str, LOG_COLOR, 6, screen::log::y);
        screen::log::add();
    }else{}
}

void screen::log::add()
{
        screen::log::y++;
        if(y > HEIGHT_SIZE){y = HEIGHT_SIZE;}
}

void screen::exceptions::error(char *str)
{
    screen::Text::print("[ERROR] ", RED, 0, screen::log::y);
    screen::Text::print(str, LOG_COLOR, 8, screen::log::y);
    screen::log::add();
}

void screen::exceptions::success(char *str)
{
    screen::Text::print("[SUCCESS] ", GREEN, 0, screen::log::y);
    screen::Text::print(str, LOG_COLOR, 10, screen::log::y);
    screen::log::add();
}