#include <cmp_store.h>
#include <int_literal.h>
#include <exception>

using namespace L2;

Comparison_Store::Comparison_Store(Cmp_Op op,
                                   compiler_ptr<Value_Source> lhs,
                                   compiler_ptr<Value_Source> rhs,
                                   compiler_ptr<Writable> target) :
        op(op),
        target(target),
        lhs(std::move(lhs)),
        rhs(std::move(rhs)){}




void Comparison_Store::dump(std::ostream &out) const{
        out << "(";
        target->dump(out);
        out << " <- ";
        lhs->dump(out);
        out << " ";
        switch(op){
        case(Cmp_Op::less):
                out << "<";
                break;
        case(Cmp_Op::less_Equal):
                out << "<=";
                break;
        case(Cmp_Op::equal):
                out << "=";
                break;
        default:
                throw std::logic_error("invalid comparison op to dump in cmp store");
        }
        out << " ";
        rhs->dump(out);
        out << ")";
}

io_set_t Comparison_Store::gen() const{
        io_set_t gen_st;

        insert_name(gen_st, lhs);
        insert_name(gen_st, rhs);

        return gen_st;
}

io_set_t Comparison_Store::kill() const{
        io_set_t kill_st;

        insert_name(kill_st, target);

        return kill_st;
}

Inst_Ptr Comparison_Store::replace_vars(std::unordered_map<std::string, std::string> reg_map) const{
        return Inst_Ptr{new Comparison_Store{op,
                                sub_reg_mapping<Value_Source>(reg_map, lhs),
                                sub_reg_mapping<Value_Source>(reg_map, rhs),
                                sub_reg_mapping<Writable>(reg_map, target)}};
}

void Comparison_Store::accept(Instruction_Visitor &v){
        v.visit(this);
}

void Comparison_Store::accept(AST_Item_Visitor &v){
        v.visit(this);
}
