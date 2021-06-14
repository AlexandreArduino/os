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
        TextCursor *cursor;
    };
};

#endif