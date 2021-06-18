#include "math.h"
#include "../kernel/kernel.h"
using namespace kernel;
void Test::math()
{
    kernel::print("Test of the pow function : 8^8 = ", YELLOW);
    kernel::PrintIntLn(lib::math::pow(8, 8), YELLOW);
    kernel::PrintIntLn(lib::math::SquareRoot(-5));
}