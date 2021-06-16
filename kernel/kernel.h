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
// #include "../dev/integer.h"
#include "../dev/gdt.h"
#define DEFAULT_COLOR_PRINT GRAY
#define BOOTLOADER_SPACE 0x7C00
#define BOOTLOADER_EXTENDED_SPACE 0x7E00
#define KERNEL_SPACE 0x8600
#define TOP_STACK 0x7C00
#define BOTTOM_STACK 0x7D99
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
    void sti();
    void cli();
};
#endif