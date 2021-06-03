#pragma once
#include "types.h"
namespace KernelLib
{
    int memcopy(void*, void*, int);
    void cli();
    void sti();
};

void *memcpy(char *dst, char *src, int n);

class string
{
public:
    string(const char *str);
    ~string();
    u8 length();
private:
    const char *_str;
};