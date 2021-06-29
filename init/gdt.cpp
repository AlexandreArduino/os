#include "../kernel/kernel.h"
void GDT::init()
{
    Screen::info("Loading Global Descriptors Table...");
    LoadGDT();
    Screen::success("Global Descriptors Table loaded!");
}