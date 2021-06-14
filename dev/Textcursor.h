#ifndef __DEV_CURSOR_H
#define __DEV_CURSOR_H

namespace Dev
{
    class Cursor
    {
    public:
        Cursor(int location);
        Cursor(int x, int y);
        ~Cursor();
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
};

#endif