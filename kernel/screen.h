#pragma once
#include "types.h"
#define VIDEO_MEMORY 0xB8000
#define SIZE_SCREEN 4000
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
namespace screen
{
    void clear();
    void putchar(char c, u16 color, u16 position);
    void print(char *str, u16 color, u16 position);
};