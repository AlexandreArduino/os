#ifndef __KERNEL_UTILS_H
#define __KERNEL_UTILS_H
#include "types.h"
#include "screen/screen.h"
#include "screen/log.h"
#include "hardware/IO.h"
#include "../lib/integer.h"
#include "../lib/string.h"
#include "../lib/math.h"
namespace kernel
{
    unsigned short PrintNumberAutomaticPosition();
    void clear();
    void println(char *str);
    void print(char *str);
    void scroll(u8 n);
    void PrintIntLn(int value);
};
#endif