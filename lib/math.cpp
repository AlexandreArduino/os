#include "../kernel/kernel.h"

int lib::math::pow(int value, int exponent)
{
    for(int i = 0;i < exponent;i++)
    {
        value *= exponent;
    }
    return value;
}