#ifndef __LIB_INTEGER__H
#define __LIB_INTEGER__H
namespace lib
{
    class Integer
    {
    public:
        Integer(int value);
        ~Integer();
        void ToString();
    private:
        int _value;
    };
};
#endif