#pragma once
#include "../types.h"
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
namespace screen
{
    void clear();

   /* namespace TextCursor
    {
        extern unsigned short x;
        extern unsigned short y;
        extern unsigned short location;
        unsigned short GetLocation(unsigned short x, unsigned short y);
        void SetPosition(unsigned short position);
        void Refresh(unsigned short x, unsigned short y);
        void RefreshWithLocation();
        void AddValueCursor(unsigned short value);
    };*/
    namespace Text
    {
        void putchar(char c, unsigned short color, unsigned short x, unsigned short y);
        void putchar(char c, unsigned short color, unsigned short position);
        void print(char *str, unsigned short color, unsigned short position);
        void print(char *str, unsigned short color, unsigned short x, unsigned short y);
        unsigned short GetLocation(unsigned short x, unsigned short y);
        void scroll(u8 NumberLines);
    };

    namespace Integer
    {
        void PrintInt(int value, u8 base, unsigned short position, u8 color);
        void PrintInt(int value, u8 base, unsigned short x, unsigned short y, u8 color);
    };
};
