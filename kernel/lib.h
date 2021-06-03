#pragma once

namespace KernelLib
{
    int memcopy(void*, void*, int);
    void cli();
    void sti();
};

void *memcpy(char *dst, char *src, int n);