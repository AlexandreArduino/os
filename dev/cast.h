#ifndef CAST_DEV_H
#define CAST_DEV_H

#define ASCII_NUM_OFFSET 48

namespace Dev
{
    namespace Hexadecimal
    {
        void ToString(int value);
    };
    namespace Integer
    {
        void ToString(int value);
        int Length(int value);
    };
};

#endif