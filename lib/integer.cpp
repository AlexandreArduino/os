#include "integer.h"
#include "../kernel/screen/log.h"
Integer::Integer(int value)
{
    _value = value;
}

Integer::~Integer(){}

float Integer::ToFloat()
{
    return (float)_value;
}

void Integer::ToString()
{
    
}