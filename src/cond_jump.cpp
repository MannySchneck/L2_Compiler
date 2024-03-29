#include <cond_jump.h>
#include <cmp_ops.h>
#include <int_literal.h>
#include <regs.h>

using namespace L2;

Cond_Jump::Cond_Jump(Cmp_Op cmp,
                     compiler_ptr<Value_Source> cmp_lhs,
                     compiler_ptr<Value_Source> cmp_rhs,
                     L2_Label true_target,
                     L2_Label false_target) :
        cmp(cmp),
        cmp_lhs(std::move(cmp_lhs)),
        cmp_rhs(std::move(cmp_rhs)),
        true_target(true_target),
        false_target(false_target){}

void Cond_Jump::dump(std::ostream &out) const{
        out << "(";
        out << "cjump ";
        cmp_lhs->dump(out); out << " ";

        switch(cmp){
        case(Cmp_Op::less):
                out << "<";
                break;
        case(Cmp_Op::less_Equal):
                out << "<=";
                break;
        case(Cmp_Op::equal):
                out << "=";
                break;
        }

        out << " "; cmp_rhs->dump(out);
        out << " "; true_target.dump(out);
        out << " "; false_target.dump(out);
        out << ")";
}

io_set_t Cond_Jump::gen() const{
        io_set_t gen_st;

        insert_name(gen_st, cmp_lhs);
        insert_name(gen_st, cmp_rhs);

        return gen_st;
}

io_set_t Cond_Jump::kill() const{
        io_set_t kill_st;

        return kill_st;
}

L2_Label Cond_Jump::get_true() const{
        return true_target;
}
L2_Label Cond_Jump::get_false() const{
        return false_target;
}


std::vector<Inst_Posn> Cond_Jump::find_successors(Inst_Posn pos, std::vector<Inst_Ptr> & instrs){
        return{find_target(instrs.begin(), instrs.end(), true_target),
                        find_target(instrs.begin(), instrs.end(), false_target)};
}

Inst_Ptr Cond_Jump::replace_vars(std::unordered_map<std::string, std::string> reg_map) const{
        return Inst_Ptr{new Cond_Jump{cmp,
                                sub_reg_mapping<Value_Source>(reg_map, cmp_lhs),
                                sub_reg_mapping<Value_Source>(reg_map, cmp_rhs),
                                true_target,
                                false_target}};
}

void Cond_Jump::accept(Instruction_Visitor &v){
        v.visit(this);
}

void Cond_Jump::accept(AST_Item_Visitor &v){
        v.visit(this);
}
