#include "screen.h"
#include "../kernel/kernel.h"

void Test::screen()
{
    int c = Screen::cursor->GetLocation();
    kernel::println("This is the screen test function!");
    /*Screen::ClearChar(c);
    Screen::ClearLine(5);
    Screen::scroll(2);*/
}