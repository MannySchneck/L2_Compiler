#include <shop.h>
#include <int_literal.h>
#include <regs.h>

using namespace L2;

Shop::Shop(Shop_Op op, compiler_ptr<Writable> lhs, compiler_ptr<Value_Source> rhs):
        op(op),
        lhs(std::move(lhs)),
        rhs(std::move(rhs)){}

void Shop::dump(std::ostream &out) const{
        out << "(";
        lhs->dump(out);
        switch(op){
        case(Shop_Op::left_Shift):
                out << " <<= ";
                break;
        case(Shop_Op::right_Shift):
                out << " >>= ";
                break;
        }
        rhs->dump(out);
        out << ")";
}

io_set_t Shop::gen() const{
        io_set_t gen_st;

        insert_name(gen_st, lhs);
        insert_name(gen_st, rhs);

        return gen_st;
}

io_set_t Shop::kill() const{
        io_set_t kill_st;

        return kill_st;
}

Inst_Ptr Shop::replace_vars(std::unordered_map<std::string, std::string> reg_map) const{
        return Inst_Ptr{new Shop{op,
                                sub_reg_mapping<Writable>(reg_map, lhs),
                                sub_reg_mapping<Value_Source>(reg_map, rhs)}};

}

void Shop::accept(Instruction_Visitor &v){
        v.visit(this);
}

void Shop::accept(AST_Item_Visitor &v){
        v.visit(this);
}