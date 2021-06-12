#include "kernel.h"
void *__gxx_personality_v0;
void *_Unwind_Resume;
using namespace kernel;
extern "C" void _start()
{
    /*screen::clear();
    screen::exceptions::success("Kernel loaded at 0x8600!");
    screen::log::println("Loading the whole kernel ...");
    screen::log::println("Here you will find the real cursor position");
    lib::integer::print(screen::TextCursor::location, PrintNumberAutomaticPosition(), YELLOW);
    screen::log::println("It works!");*/
    clear();
    /*println("Kernel loaded at 0x8600!");
    println("Loading the whole kernel ...");
    print("Current cursor position : ");
    // PrintIntLn(screen::TextCursor::location);
    PrintIntLn(123456789);*/
    Dev::TextCursor cursor(0, 48000);
    while(1);
}
