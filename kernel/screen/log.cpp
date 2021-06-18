#include "../kernel.h"

void log::info(char *str)
{
    kernel::print("[INFOS] ");
    kernel::println(str);
}

void log::success(char *str)
{
}

void log::error(char *str)
{

}