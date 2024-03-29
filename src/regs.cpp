#include <regs.h>
#include <unordered_map>

using namespace L2;

Reg::Reg(std::string name) :
        L2_ID(name){}

Reg::~Reg() = default;

Reg Reg::get_eight_bit() const{
        return Reg(eight_bit_name.at(name));
}


const std::unordered_map<std::string, std::string> Reg::eight_bit_name =
{
        {"r8", "r8b"},
        {"r9", "r9b"},
        {"r10", "r10b"},
        {"r11", "r11b"},
        {"r12", "r12b"},
        {"r13", "r13b"},
        {"r14", "r14b"},
        {"r15", "r15b"},
        {"rax", "al"},
        {"rbx", "bl"},
        {"rcx", "cl"},
        {"rdx", "dl"},
        {"rdi", "dil"},
        {"rsi", "sil"},
        {"rbp", "bpl"}
};


Writable_Reg::Writable_Reg(std::string name) :
        Reg(name) {}


void Reg::dump(std::ostream &out) const{
        out << name;
}

void Writable_Reg::dump(std::ostream &out) const{
        Reg::dump(out);
}


