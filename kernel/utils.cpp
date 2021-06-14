#include "kernel.h"

unsigned short kernel::PrintNumberAutomaticPosition()
{
    return screen::TextCursor::location*2 - 2;
}

void kernel::clear()
{
    Dev::Screen::clear();
}

void kernel::println(char *str)
{
    Dev::Screen::println(str, DEFAULT_COLOR_PRINT);
}

void kernel::print(char *str)
{
    Dev::Screen::print(str, DEFAULT_COLOR_PRINT);
}

void kernel::scroll(u8 n)
{
    Dev::Screen::scroll(n);
}

void kernel::PrintInt(int value)
{
    Dev::Integer::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintIntLn(int value)
{
    Dev::Integer::println(value, DEFAULT_COLOR_PRINT);
}