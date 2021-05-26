#include "log.h"
#include "screen.h"
#include "log.h"

#ifndef LOG
#define LOG 1
#endif

unsigned int screen::log::line = 0;

void screen::log::log(char *infos)
{
    if(LOG)
    {
        print(infos, WHITE, 0, line);
        line++;
        screen::CursorPosition = LENGTH_LINE*line;
        screen::setCursorPosition(screen::CursorPosition);
    }else{}
}