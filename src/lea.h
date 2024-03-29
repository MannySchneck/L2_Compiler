#pragma once

#include <marker_classes.h>
#include <instruction.h>
#include <regs.h>

namespace L2 {

        class LEA : public Instruction{
        public:
                LEA(compiler_ptr<Writable> target,
                    compiler_ptr<Writable> base,
                    compiler_ptr<Writable> offset,
                    int64_t mult);

                void dump(std::ostream &out) const override;

                io_set_t gen() const override;
                io_set_t kill() const override;


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;

                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;
        private:
                compiler_ptr<Writable> target;
                compiler_ptr<Writable> base;

                compiler_ptr<Writable> offset;
                int64_t mult; // 0 | 2 | 4 | 8

                friend class Get_Ids_Visitor;
        };


}  // L2
