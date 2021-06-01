#pragma once
#include "types.h"
struct IDTDescriptor
{
    u16 Offset_0_15;
    u16 SegmentSelector;
    u16 Type;
    u16 Offset_16_31;
}__attribute__((packed));

    void init_desc();