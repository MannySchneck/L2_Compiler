#pragma once
#include <marker_classes.h>
#include <instruction.h>

#include <string>
#include <ostream>


namespace L2 {

        class L2_Label :
                public virtual Source,
                public virtual Callable,
                public Instruction
        {
        public:
                L2_Label();
                L2_Label(std::string label);

                void dump(std::ostream &out) const override;
                std::string labelName;

                io_set_t gen() const override;
                io_set_t kill() const override;

                inline bool operator==(const L2_Label &rhs){
                        return labelName == rhs.labelName;
                }
                inline bool operator!=(const L2_Label &rhs){
                        return ! (*this == rhs);
                }


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const override;

                void accept(Instruction_Visitor &v) override;
                void accept(AST_Item_Visitor &v) override;
        };

        class L2_Target_Label :
                public L2_Label
        {
        public:
                L2_Target_Label();
                L2_Target_Label(std::string label);


                Inst_Ptr replace_vars(std::unordered_map<std::string, std::string> reg_map) const;

                void dump(std::ostream &out) const override;
        };

}  // L2

