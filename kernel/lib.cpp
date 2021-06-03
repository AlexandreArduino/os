#include "lib.h"
#include "log.h"
#include "types.h"
namespace KernelLib
{
    void* memcopy(char *src, char *dst, int value)
    {
        char *p = dst;
        while(value--)
            *dst++ = *src++;
        return p;
    }

    void cli()
    {
        screen::log::print("Disabling interrupts ...");
        asm volatile("cli": :);
    }

    void sti()
    {
        screen::log::print("Setting interrupts ...");
        asm volatile("sti": :);
    }
};

void *memcpy(char *dst, char *src, int n)
{
	char *p = dst;
	while (n--)
		*dst++ = *src++;
	return p;
}

string::string(const char *str)
{
    _str = str;
}

string::~string(){}

u8 string::length()
{
    const char *__str = _str;
    u8 count = 0;
    while(*__str != 0)
    {
        count++;
        *__str++;
    }
    return count;
}