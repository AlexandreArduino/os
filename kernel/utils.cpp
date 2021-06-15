#include "kernel.h"

unsigned short kernel::PrintNumberAutomaticPosition()
{
    return screen::TextCursor::location*2 - 2;
}

void kernel::clear()
{
    clear();
}

void kernel::println(char *str)
{
    println(str, DEFAULT_COLOR_PRINT);
}

void kernel::print(char *str)
{
    print(str, DEFAULT_COLOR_PRINT);
}

void kernel::scroll(u8 n)
{
    Screen::scroll(n);
}

void kernel::PrintInt(int value)
{
    Dev::Integer::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintIntLn(int value)
{
    Dev::Integer::println(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHex(int value)
{
    Dev::Hexadecimal::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHexLn(int value)
{
    Dev::Hexadecimal::println(value, DEFAULT_COLOR_PRINT);
}