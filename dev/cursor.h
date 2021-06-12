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
        int VerifCoos(int location);
    private:
        int location;
        int x;
        int y;
    };
};

#endif