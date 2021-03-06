#ifndef __KERNEL_UTILS_H
#define __KERNEL_UTILS_H
#include "types.h"
#include "screen/screen.h"
#include "hardware/IO.h"
#include "../lib/integer.h"
#include "../lib/string.h"
#include "../lib/math.h"
#include "screen/TextCursor.h"
#include "../test/math.h"
#include "../lib/float.h"
#include "../test/screen.h"
#include "../boot/BootInfos.h"
#include "hardware/pic.h"
#define DEFAULT_COLOR_PRINT GRAY
#define BOOTLOADER_SPACE 0x7C00
#define BOOTLOADER_EXTENDED_SPACE 0x7E00
#define KERNEL_SPACE 0x8600
#define TOP_STACK 0x7C00
#define BOTTOM_STACK 0x7D99
#define TEST_ON_BOOT 0
#define LOG_ON_BOOT 1
namespace kernel
{
    void clear();
    void println(char *str);
    void print(char *str);
    void println(char *str, u8 color);
    void print(char *str, u8 color);
    void scroll(u8 n);
    void PrintInt(int value);
    void PrintIntLn(int value);
    void PrintInt(int value, u8 color);
    void PrintIntLn(int value, u8 color);
    void PrintHex(int value);
    void PrintHexLn(int value);
    void PrintHex(int value, u8 color);
    void PrintHexLn(int value, u8 color);
    void sti();
    void cli();
    void memcpy(void *dest, void *src, int length);
    void test(); 
};

#endif
