#include "../kernel.h"

void log::info(char *str)
{
    kernel::print("[INFOS] ");
    kernel::println(str);
}

void log::success(char *str)
{
    kernel::print("[SUCCESS] ", GREEN);
    kernel::println(str);
}

void log::error(char *str)
{
    kernel::print("[ERROR] ", RED);
    kernel::println(str);
}