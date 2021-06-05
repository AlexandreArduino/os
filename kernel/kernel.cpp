#include "screen/log.h"
#include "../lib/integer.h"
#include "../lib/string.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
void itoa(int number, char *str, int base);
int int_length(int value);
extern "C" void _start()
{
    screen::clear();
    screen::exceptions::success("Kernel loaded at 0x8600!");
    screen::log::print("Loading the whole kernel ...");
    char *str="";
    itoa(56, str, 10);
    while(1);
}
void itoa(int number, char *str, int base)
{
    int _value = number;
    if(!_value){
        screen::log::print("The value is NULL");
        str[0] = '0';
        str[1] = '\0';
        screen::log::print(str);}
    else{
        screen::log::print("The value is != 0");
        int rem;
        int i = 0;
        int h = int_length(_value);
        while(_value != 0)
        {
            rem = _value % base;
            //str[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
            str[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
            i++;
            _value /= base;
        }
        str[i] = '\0';
        screen::log::print(str);
    }
        
}

int int_length(int value)
{
    int count = 0;
    while(value > 0)
    {
        count++;
        value = (int)value/10;
    }
    return count;
}