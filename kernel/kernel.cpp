#include "log.h"
#include "screen.h"

using namespace screen;
using namespace log;

extern "C" void _start()
{
    clear();
    screen::log::log("Kernel loaded!");
    screen::log::log("Setting up text cursor ...");
    screen::log::log("Text cursor set!");
    while(1);
}