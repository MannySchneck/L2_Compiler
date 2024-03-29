#pragma once
#include <marker_classes.h>
#include <instruction.h>
#include <memory>
#include <string>
#include <set>

namespace L2 {

        enum class Binop_Op{
                store,
                // arithmetic ops
                add_Assign,
                sub_Assign,
                mult_Assign,
                bit_And_Assign,
                };

        class Binop : public Instruction
        {
        public:
                Binop(Binop_Op op, compiler_ptr<Binop_Lhs> lhs, compiler_ptr<Binop_Rhs> rhs);


                std::string stringify_binop_op(Binop_Op op) const;
                void dump(std::ostream &out) const override;

               io_set_t gen() const override;
               io_set_t kill() const override;


                Binop_Op op;


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;

                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;

                compiler_ptr<Binop_Lhs> lhs;
                compiler_ptr<Binop_Rhs> rhs;
        };


}  // L2
