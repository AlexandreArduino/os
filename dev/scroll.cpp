#include "scroll.h"
#include "../kernel/screen/screen.h"
#include "../kernel/types.h"
#include "../kernel/screen/log.h"
void Dev::scroll::Scroll(u8 line)
{
    //char *cursor = (char*)(VIDEO_MEMORY + LENGTH_LINE*line*2);
    int last_location = screen::TextCursor::location;
    char *cursor;
    char *destination;
    int i;
   // unsigned short last_x_cursor = screen::TextCursor::x;
    //unsigned short last_y_cursor = screen::TextCursor::y;
    for(i = 0; i < SIZE_SCREEN - line*LENGTH_LINE;i++)
    {
        cursor = (char*)(VIDEO_MEMORY + LENGTH_LINE*line*2 + i);
        destination = (char*)(VIDEO_MEMORY + i);
        *destination = *cursor;
    }
    screen::TextCursor::SetPosition(last_location - line*LENGTH_LINE - 1);
    screen::log::y -= line;
    //last_y_cursor -= line;
    //screen::TextCursor::SetPosition(screen::TextCursor::GetLocation(last_x_cursor, last_y_cursor));
}