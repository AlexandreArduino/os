#pragma once
#include "screen.h"
#ifndef LOG
#define LOG 1 //Modify to turn ON/OFF the logs
#endif

#ifndef LOG_COLOR
#define LOG_COLOR GRAY //Modify the color if you want logs
#endif

namespace log
{
    void info(char *str);
    void success(char *str);
    void error(char *str);
};