#include "kernel.h"

unsigned short kernel::PrintNumberAutomaticPosition()
{
    // return screen::TextCursor::location*2 - 2;
    return 0;
}

void kernel::clear()
{
    Screen::clear();
}

void kernel::println(char *str)
{
    Screen::println(str, DEFAULT_COLOR_PRINT);
}

void kernel::print(char *str)
{
    Screen::print(str, DEFAULT_COLOR_PRINT);
}

void kernel::scroll(u8 n)
{
    Screen::scroll(n);
}

void kernel::PrintInt(int value)
{
    Integer::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintIntLn(int value)
{
    Integer::println(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHex(int value)
{
    Hexadecimal::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHexLn(int value)
{
    Hexadecimal::println(value, DEFAULT_COLOR_PRINT);
}