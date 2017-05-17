#pragma once

#include <marker_classes.h>
#include <instruction.h>

namespace L2{
        class Stack_Arg :
                public Binop_Rhs{
        public:
                Stack_Arg(int64_t offset);

                void dump(std::ostream &out) const override;
                void accept(AST_Item_Visitor &v) override;

                int64_t offset;
        };
}
