#include <memory_ref.h>
#include <marker_classes.h>
#include <instruction.h>

using namespace L2;

Memory_Ref::Memory_Ref(compiler_ptr<L2_ID> base, int64_t offset) :
        base(std::move(base)),
        offset(offset)
{
        if(offset % 8 != 0){
                throw std::invalid_argument("memory ref must be multiple of 8");
        }
};

compiler_ptr<L2_ID> Memory_Ref::get_base(){
        return base;
}



void Memory_Ref::dump(std::ostream &out) const{
        out << "(mem ";
        base->dump(out);
        out << " " << offset;
        out << ")";
}


void Memory_Ref::accept(AST_Item_Visitor &v){
        v.visit(this);
}
