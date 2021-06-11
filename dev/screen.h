#ifndef __DEV__CURSOR_H
#define __DEV__CURSOR_H

namespace Dev
{
    class Cursor
    {
    public:
        Cursor(unsigned short x, unsigned short y);
        Cursor(unsigned short location);
        void SetLocation(unsigned short location);
        void SetLocation(unsigned short x, unsigned short y);
        unsigned short GetLocationWithCoos(unsigned short x, unsigned short y);
        unsigned short GetX();
        unsigned short GetY();
        void AddValueCursor(unsigned short value);
        void AddX(unsigned short NewX);
        void AddY(unsigned short NewY);
        ~Cursor();
    private:
        unsigned short x;
        unsigned short y;
        unsigned short location;
        void CorrectCoos();
    };
};

#endif