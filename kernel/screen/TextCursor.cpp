#include "../kernel.h"

TextCursor::TextCursor(int location)
{
    TextCursor::SetLocation(location);
}

TextCursor::TextCursor(int x, int y)
{
    TextCursor::SetLocation(x, y);
}

TextCursor::~TextCursor(){}

void TextCursor::SetLocation(int location)
{
    TextCursor::location = TextCursor::VerifCoos(location);
    TextCursor::x = TextCursor::GetX();
    TextCursor::y = TextCursor::GetY();
    IO::outb(0x3D4, 0x0F);
    IO::outb(0x3D5, (unsigned char)(TextCursor::location & 0xFF));
    IO::outb(0x3D4, 0x0E);
    IO::outb(0x3D5, (unsigned char)((TextCursor::location >> 8) & 0xFF));
}

int TextCursor::VerifCoos(int location)
{
    if(location < 0)
        return 0;
    else if(location > SIZE_SCREEN)
        return SIZE_SCREEN - 1;
    else
        return location;
}

void TextCursor::SetLocation(int x, int y)
{
    TextCursor::SetLocation(TextCursor::GetLocation(x, y));
}

int TextCursor::GetLocation(int x, int y)
{
    return x + y*LENGTH_LINE;
}

int TextCursor::GetX()
{
    return TextCursor::location % LENGTH_LINE;
}

int TextCursor::GetY()
{
    return (int)TextCursor::location / LENGTH_LINE;
}

int TextCursor::GetLocation()
{
    return TextCursor::location;
}

void TextCursor::AddValue(int value)
{
    TextCursor::SetLocation(TextCursor::location + value);
}

void TextCursor::AddX(int x)
{
    TextCursor::SetLocation(TextCursor::GetX() + x, TextCursor::GetY());
}

void TextCursor::AddY(int y)
{
    TextCursor::SetLocation(TextCursor::GetX(), TextCursor::GetY() + y);
}