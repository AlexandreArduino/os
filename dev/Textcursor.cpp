#include "cursor.h"
#include "../kernel/kernel.h"

Dev::Cursor::Cursor(int location)
{
    Dev::Cursor::SetLocation(location);
}

Dev::Cursor::Cursor(int x, int y)
{
    Dev::Cursor::SetLocation(x, y);
}

Dev::Cursor::~Cursor(){}

void Dev::Cursor::SetLocation(int location)
{
    Dev::Cursor::location = Dev::Cursor::VerifCoos(location);
    Dev::Cursor::x = Dev::Cursor::GetX();
    Dev::Cursor::y = Dev::Cursor::GetY();
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

void Dev::Cursor::SetLocation(int x, int y)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetLocation(x, y));
}

int Dev::Cursor::GetLocation(int x, int y)
{
    return x + y*LENGTH_LINE;
}

int Dev::Cursor::GetX()
{
    return Dev::Cursor::location % LENGTH_LINE;
}

int Dev::Cursor::GetY()
{
    return (int)Dev::Cursor::location / LENGTH_LINE;
}

int Dev::Cursor::GetLocation()
{
    return Dev::Cursor::location;
}

void Dev::Cursor::AddValue(int value)
{
    Dev::Cursor::SetLocation(Dev::Cursor::location + value);
}

void Dev::Cursor::AddX(int x)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetX() + x, Dev::Cursor::GetY());
}

void Dev::Cursor::AddY(int y)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetX(), Dev::Cursor::GetY() + y);
}