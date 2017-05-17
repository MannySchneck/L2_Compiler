#pragma once
#include <ostream>
#include <translatable.h>

namespace L2{

        enum class Cmp_Op{
                equal,
                less,
                less_Equal,
                };

        enum class Cmp_Case{
                both_Int,
                flip,
                };


        void output_comparison(Translatable* lhs,
                               Translatable* rhs,
                               std::ostream& out);
}
