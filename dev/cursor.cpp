#include "cursor.h"
#include "../kernel/kernel.h"

Dev::Cursor::Cursor(int location)
{
    Dev::Cursor::SetLocation(location);
}

Dev::Cursor::Cursor(int x, int y)
{

}

Dev::Cursor::~Cursor(){}

void Dev::Cursor::SetLocation(int location)
{
    Dev::Cursor::location = Dev::Cursor::VerifCoos(location);
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(Dev::Cursor::location & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((Dev::Cursor::location >> 8) & 0xFF));
}

int Dev::Cursor::VerifCoos(int location)
{
    if(location < 0)
        return 0;
    else if(location > SIZE_SCREEN)
        return SIZE_SCREEN - 1;
    else
        return location;
}