#include "kernel.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
using namespace kernel;
extern "C" void _start()
{
    clear();
    TextCursor cursor(5);
    while(1);
}