#include "integer.h"
#include "../kernel/screen/log.h"
lib::Integer::Integer(int value)
{
    _value = value;
}

lib::Integer::~Integer(){}

void lib::Integer::ToString()
{
    int __value = _value;
    char text[20];
    int i = 0;
    int c = 0;
    if(!__value)
        screen::log::print("0");
    else{
        if(__value < 0)
        {
            __value = -__value;
        }
        while(__value >= 100)
            __value -= 100;
            c++;
        text[i++] = c + 48;
        c = 0;
        while(__value >= 10)
            __value -= 10;
            c++;
        text[i++] = c + 48;
        text[i] = __value + 48;
        screen::log::print("pl");
    }
}