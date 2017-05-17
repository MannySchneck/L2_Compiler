#pragma once

#include <marker_classes.h>
namespace L2{
#include <var.h>
        class Var : public Writable,
                    public L2_ID{
        public:
                explicit Var(std::string name);

                void dump(std::ostream &out) const override;
        private:
        };
}


