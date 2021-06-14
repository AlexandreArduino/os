#ifndef __DEV_SCREEN_H
#define __DEV_SCREEN_H
#include "../kernel/kernel.h"
namespace Dev
{
    class Screen
    {
    public:
        Screen(int CursorLocation);
        ~Screen();
        void putchar(char c, unsigned int position, u8 color);
        void putchar(char c, u8 color);
        void print(char *str, u8 color);
        void println(char *str, u8 color);
        void print(char *str, unsigned int position, u8 color);
        void println(char *str, unsigned int position, u8 color);
        void scroll(u8 NumberLines);
        TextCursor *cursor;
    };
};

#endif