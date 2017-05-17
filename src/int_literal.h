#pragma once

#include <translatable.h>
#include <marker_classes.h>
#include <instruction.h>

namespace L2{
        class Integer_Literal :
                public Value_Source
        {
        public:
                Integer_Literal(std::string);
                void dump(std::ostream &out) const override;
                int64_t value;
                void accept(AST_Item_Visitor &v) override;
        };
}
