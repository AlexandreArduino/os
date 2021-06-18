#include "kernel.h"

void kernel::clear()
{
    Screen::clear();
}

void kernel::println(char *str)
{
    Screen::println(str, DEFAULT_COLOR_PRINT);
}

void kernel::print(char *str)
{
    Screen::print(str, DEFAULT_COLOR_PRINT);
}

void kernel::println(char *str, u8 color)
{
    Screen::println(str, color);
}

void kernel::print(char *str, u8 color)
{
    Screen::print(str, color);
}

void kernel::scroll(u8 n)
{
    Screen::scroll(n);
}

void kernel::PrintInt(int value)
{
    Integer::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintIntLn(int value)
{
    Integer::println(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintInt(int value, u8 color)
{
    Integer::print(value, color);
}

void kernel::PrintIntLn(int value, u8 color)
{
    Integer::println(value, color);
}

void kernel::PrintHex(int value)
{
    Hexadecimal::print(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHexLn(int value)
{
    Hexadecimal::println(value, DEFAULT_COLOR_PRINT);
}

void kernel::PrintHex(int value, u8 color)
{
    Hexadecimal::print(value, color);
}

void kernel::PrintHexLn(int value, u8 color)
{
    Hexadecimal::println(value, color);
}

void kernel::cli()
{
    asm volatile("cli"::);
}

void kernel::sti()
{
    asm volatile("sti"::);
}

void kernel::memcpy(void *dest, void *src, int length)
{
    kernel::print("Copying in memory from ");
    kernel::PrintHex(src);
    kernel::print(" to ");
    kernel::PrintHex(dest);
    kernel::println(" ...");
    char *_src = (char*)src;
    char *_dest = (char*)dest;
    for(int i = 0; i < length;i++)
    {
        _dest[i] = _src[i];
    }
}

void kernel::init()
{
    TextCursor MainTextCursor(0);
    Screen::init(MainTextCursor);
    clear();
    print("Kernel loaded at ", LIGHT_PURPLE);
    PrintHex(KERNEL_SPACE, LIGHT_PURPLE);
    println("!", LIGHT_PURPLE);
    print("Bootloader loaded from ");
    PrintHex(BOOTLOADER_SPACE);
    print(" to ");
    PrintHex(BOOTLOADER_EXTENDED_SPACE);
    println("!");
    print("Top of the stack at ");
    PrintHex(TOP_STACK);
    println("!");
    print("Bottom of the stack at ");
    PrintHex(BOTTOM_STACK);
    println("!");
    print("Test of the pow function : 8^8 = ", YELLOW);
    PrintIntLn(lib::math::pow(8, 8), YELLOW);
}