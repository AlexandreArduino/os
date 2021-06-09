#pragma once
#include "screen.h"
#ifndef LOG
#define LOG 1 //Modify to turn ON/OFF the logs
#endif

#ifndef LOG_COLOR
#define LOG_COLOR GRAY //Modify the color if you want logs
#endif

namespace screen
{
    namespace log
    {
        extern unsigned short y;
        extern unsigned short x_offset;
        void println(char *str);
        void print(char *str);
        void add();
    };
    namespace exceptions
    {
        void error(char *str);
        void success(char *str);
    };
};