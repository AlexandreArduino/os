#ifndef __KERNEL_UTILS_H
#define __KERNEL_UTILS_H
#include "types.h"
#include "screen/screen.h"
#include "screen/log.h"
#include "hardware/IO.h"
#include "../lib/integer.h"
#include "../lib/string.h"
#include "../lib/math.h"
// #include "../dev/cursor.h"
#include "screen/TextCursor.h"
// #include "../dev/screen.h"
#include "../dev/integer.h"
#define DEFAULT_COLOR_PRINT GRAY
#define KERNEL_SPACE 0x8600
namespace kernel
{
    unsigned short PrintNumberAutomaticPosition();
    void clear();
    void println(char *str);
    void print(char *str);
    void scroll(u8 n);
    void PrintInt(int value);
    void PrintIntLn(int value);
    void PrintHex(int value);
    void PrintHexLn(int value);
};
#endif