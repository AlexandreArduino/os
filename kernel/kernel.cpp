#include "kernel.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
void *__cxa_atexit;
void *__dso_handle;
using namespace kernel;
extern "C" void _start()
{
    clear();
    Screen::info("Kernel successfully loaded!");
    BootProcess::Infos::main();
    pic::init();
    while(1);
}
