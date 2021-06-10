#include "kernel.h"

unsigned short kernel::PrintNumberAutomaticPosition()
{
    return screen::TextCursor::location*2 - 2;
}

void kernel::clear()
{
    screen::clear();
}

void kernel::println(char *str)
{
    screen::log::println(str);
}

void kernel::print(char *str)
{
    screen::log::print(str);
}

void kernel::scroll(u8 n)
{
    screen::Text::scroll(n);
}

void kernel::PrintIntLn(int value)
{
    lib::integer::print(value, PrintNumberAutomaticPosition(), LOG_COLOR);
}