#ifndef __INIT_GLOBAL_DESCRIPTORS_TABLE_H
#define __INIT_GLOBAL_DESCRIPTORS_TABLE_H

namespace GDT
{
    void init();
};
extern "C" void LoadGDT();
#endif