#pragma once
#include <cmp_ops.h>
#include <translatable.h>
#include <marker_classes.h>
#include <instruction.h>
#include <regs.h>
#include <memory>

namespace L2{

        class Comparison_Store : public Instruction
        {
        public:
                Comparison_Store(Cmp_Op op,
                                 compiler_ptr<Value_Source> lhs,
                                 compiler_ptr<Value_Source> rhs,
                                 compiler_ptr<Writable> target);

                void dump(std::ostream &out) const override;

                io_set_t gen() const override;
                io_set_t kill() const override;


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;

                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;
        private:
                void output_comparison_store(Translatable* lhs,
                                             Translatable* rhs,
                                             Writable_Reg target,
                                             std::string cmp_set,
                                             std::ostream& out) const;

                void output_mov(Writable_Reg target, int val, std::ostream& out) const;

                Cmp_Op op;
                compiler_ptr<Writable> target;
                compiler_ptr<Value_Source> lhs;
                compiler_ptr<Value_Source> rhs;

                friend class Get_Ids_Visitor;
        };

}
