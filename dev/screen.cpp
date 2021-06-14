#include "screen.h"
#include "../kernel/kernel.h"

/*
* To access to cursor object : Dev::Screen::cursor->function;
*/
Dev::Screen::Screen(int CursorLocation)
{
    TextCursor _cursor(CursorLocation);
    Dev::Screen::cursor = &_cursor;
    Dev::Screen::cursor->SetLocation(5);
}

Dev::Screen::~Screen(){}