#include "../kernel/kernel.h"

long long lib::math::pow(int value, int exponent)
{
    int fvalue = value;
    value = 1;
    for(int i = 0; i < exponent;i++)
        value *= fvalue;
    return value;
}

int lib::math::SquareRoot(int value)
{
    if(value < 0)
    {
        // log::error("SquareRoot for n < 0 is forbidden!");
        return 0;
    }
    else if(!value)
        return 0;
    else
        return value;
}