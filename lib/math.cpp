#include "../kernel/kernel.h"

int lib::math::pow(int value, int exponent)
{
    int fvalue = value;
    value = 1;
    for(int i = 0; i < exponent;i++)
        value *= fvalue;
    return value;
}

int lib::math::sqrt(int value)
{
    if(value < 0){
        kernel::println("Error, value in sqrt < 0!", RED);
        return value;
    }
    else if(!value)
        return 0;
    else{}
}