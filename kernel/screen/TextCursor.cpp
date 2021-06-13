#include "TextCursor.h"
#include "kernel.h"

screen::TextCursor::TextCursor(int location)
{
    screen::TextCursor::SetLocation(location);
}

screen::TextCursor::TextCursor(int x, int y)
{
    screen::TextCursor::SetLocation(x, y);
}

screen::TextCursor::~TextCursor(){}

void screen::TextCursor::SetLocation(int location)
{
    screen::TextCursor::location = screen::TextCursor::VerifCoos(location);
    screen::TextCursor::x = screen::TextCursor::GetX();
    screen::TextCursor::y = screen::TextCursor::GetY();
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(screen::TextCursor::location & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((screen::TextCursor::location >> 8) & 0xFF));
}

int screen::TextCursor::VerifCoos(int location)
{
    if(location < 0)
        return 0;
    else if(location > SIZE_SCREEN)
        return SIZE_SCREEN - 1;
    else
        return location;
}

void screen::TextCursor::SetLocation(int x, int y)
{
    screen::TextCursor::SetLocation(screen::TextCursor::GetLocation(x, y));
}

int screen::TextCursor::GetLocation(int x, int y)
{
    return x + y*LENGTH_LINE;
}

int screen::TextCursor::GetX()
{
    return screen::TextCursor::location % LENGTH_LINE;
}

int screen::TextCursor::GetY()
{
    return (int)screen::TextCursor::location / LENGTH_LINE;
}

int screen::TextCursor::GetLocation()
{
    return screen::TextCursor::location;
}

void screen::TextCursor::AddValue(int value)
{
    screen::TextCursor::SetLocation(screen::TextCursor::location + value);
}

void screen::TextCursor::AddX(int x)
{
    screen::Cursor::SetLocation(screen::Cursor::GetX() + x, screen::Cursor::GetY());
}

void screen::TextCursor::AddY(int y)
{
    screen::TextCursor::SetLocation(screen::TextCursor::GetX(), screen::TextCursor::GetY() + y);
}
