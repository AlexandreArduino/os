#pragma once
class TextCursor
{
public:
    TextCursor(int location);
    TextCursor(int x, int y);
    ~TextCursor();
    void SetLocation(int location);
    void SetLocation(int x, int y);
    int GetLocation(int x, int y);
    int GetLocation();
    int GetX();
    int GetY();
    int VerifCoos(int location);
    void AddValue(int value);
    void AddX(int x);
    void AddY(int y);
private:
    int location;
    int x;
    int y;
};