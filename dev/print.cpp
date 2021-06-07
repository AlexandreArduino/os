#include "print.h"
#include "../kernel/screen/screen.h"

void Dev::Print::PrintArray(char Buffer[], int length, unsigned short position)
{
    position -= 2;
    for(int i = length; i > 0;i--)
    {
        screen::Text::putchar(Buffer[i], GREEN, position + i*2);
    }
}