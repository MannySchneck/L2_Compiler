#pragma once

#include <marker_classes.h>
#include <instruction.h>
#include <labels.h>
#include <jump.h>


namespace L2 {

        class Goto : public Instruction,
                     public Jump{
        public:
                explicit Goto(std::string);
                explicit Goto(compiler_ptr<L2_Label> target);

                void dump(std::ostream &out) const override;

                io_set_t gen() const override;
                io_set_t kill() const override;

                std::vector<Inst_Posn> find_successors(Inst_Posn pos,
                                                        std::vector<Inst_Ptr>& instrs)  override;

                L2_Label get_target() const;


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;


                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;
        private:
                compiler_ptr<L2_Label> target;
        };


}  // L2
