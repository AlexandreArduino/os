#pragma once
#include "../kernel.h"
#define VIDEO_MEMORY 0xB8000
#define SIZE_SCREEN 2000
#define LENGTH_LINE 80
#define HEIGHT_SIZE 25
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define PURPLE 5
#define BROWN 6
#define GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define YELLOW 14
#define WHITE 15
namespace Screen
{
    void init(TextCursor _cursor);
    void putchar(char c, unsigned int position, u8 color);
    void putchar(char c, u8 color);
    void print(char *str, u8 color);
    void println(char *str, u8 color);
    void print(char *str, unsigned int position, u8 color);
    void println(char *str, unsigned int position, u8 color);
    void scroll(u8 NumberLines);
    void clear();
    extern TextCursor *cursor;
};