#pragma once

#include <translatable.h>
#include <marker_classes.h>
#include <instruction.h>
#include <regs.h>

namespace L2{
        enum class Monop_Op{
                inc,
                dec
        };

        class Monop : public Instruction{
        public:
                Monop(Monop_Op op, compiler_ptr<Writable> target);
                void dump(std::ostream &out) const override;

                io_set_t gen() const override;
                io_set_t kill() const override;


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;

                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;

                Monop_Op  op;
                compiler_ptr<Writable> target;


        private: // =(
        };

}
