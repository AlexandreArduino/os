#include "screen.h"
#include "../kernel/kernel.h"
Dev::Cursor::Cursor(unsigned short x, unsigned short y)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetLocationWithCoos(x, y));
}

Dev::Cursor::Cursor(unsigned short location)
{
    Dev::Cursor::SetLocation(location);
}

Dev::Cursor::~Cursor()
{

}

void Dev::Cursor::SetLocation(unsigned short location)
{
    Dev::Cursor::location = location;
    Dev::Cursor::x = Dev::Cursor::GetX();
    Dev::Cursor::y = Dev::Cursor::GetY();
    Dev::Cursor::location = 0;
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(Dev::Cursor::location & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((Dev::Cursor::location >> 8) & 0xFF));
}

void Dev::Cursor::SetLocation(unsigned short x, unsigned short y)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetLocationWithCoos(x, y));
}

unsigned short Dev::Cursor::GetLocationWithCoos(unsigned short x, unsigned short y)
{
    return x + y*LENGTH_LINE;
}

unsigned short Dev::Cursor::GetX()
{
    return (int)(Dev::Cursor::location % LENGTH_LINE);
}

unsigned short Dev::Cursor::GetY()
{
    return (int)(Dev::Cursor::location / LENGTH_LINE);
}

void Dev::Cursor::AddValueCursor(unsigned short value)
{
    Dev::Cursor::SetLocation(Dev::Cursor::location + value);
}

void Dev::Cursor::CorrectCoos()
{
    if(Dev::Cursor::x < 0)
    {
        Dev::Cursor::x = 0;
    }
    if(Dev::Cursor::y < 0)
    {
        Dev::Cursor::y = 0;
    }
    if(Dev::Cursor::location < 0)
        Dev::Cursor::location = 0;
    if(Dev::Cursor::location > SIZE_SCREEN)
        Dev::Cursor::location = SIZE_SCREEN;
}