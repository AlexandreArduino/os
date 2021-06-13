#include "TextCursor.h"
#include "../kernel/kernel.h"

Dev::TextCursor::TextCursor(int location)
{
    Dev::TextCursor::SetLocation(location);
}

Dev::TextCursor::TextCursor(int x, int y)
{
    Dev::TextCursor::SetLocation(x, y);
}

Dev::TextCursor::~TextCursor(){}

void Dev::TextCursor::SetLocation(int location)
{
    Dev::TextCursor::location = Dev::TextCursor::VerifCoos(location);
    Dev::TextCursor::x = Dev::TextCursor::GetX();
    Dev::TextCursor::y = Dev::TextCursor::GetY();
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(Dev::TextCursor::location & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((Dev::TextCursor::location >> 8) & 0xFF));
}

int Dev::TextCursor::VerifCoos(int location)
{
    if(location < 0)
        return 0;
    else if(location > SIZE_SCREEN)
        return SIZE_SCREEN - 1;
    else
        return location;
}

void Dev::TextCursor::SetLocation(int x, int y)
{
    Dev::TextCursor::SetLocation(Dev::TextCursor::GetLocation(x, y));
}

int Dev::TextCursor::GetLocation(int x, int y)
{
    return x + y*LENGTH_LINE;
}

int Dev::TextCursor::GetX()
{
    return Dev::TextCursor::location % LENGTH_LINE;
}

int Dev::TextCursor::GetY()
{
    return (int)Dev::TextCursor::location / LENGTH_LINE;
}

int Dev::TextCursor::GetLocation()
{
    return Dev::TextCursor::location;
}

void Dev::TextCursor::AddValue(int value)
{
    Dev::TextCursor::SetLocation(Dev::TextCursor::location + value);
}

void Dev::TextCursor::AddX(int x)
{
    Dev::Cursor::SetLocation(Dev::Cursor::GetX() + x, Dev::Cursor::GetY());
}

void Dev::TextCursor::AddY(int y)
{
    Dev::TextCursor::SetLocation(Dev::TextCursor::GetX(), Dev::TextCursor::GetY() + y);
}
