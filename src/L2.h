#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <type_traits>
#include <exception>
#include <unordered_map>

#include <lang_constants.h>

#include <ast_item.h>
#include <translatable.h>
#include <marker_classes.h>
#include <instruction.h>

#include <labels.h>
#include <regs.h>
#include <int_literal.h>
#include <var.h>
#include <memory_ref.h>
#include <stack_arg.h>

#include <binop.h>
#include <monop.h>
#include <shop.h>

#include <cmp_ops.h>
#include <cond_jump.h>
#include <cmp_store.h>

#include <lea.h>
#include <return.h>
#include <calls.h>
#include <goto.h>
#include <function.h>
#include <program.h>

class NotImplementedException : public std::logic_error
{
public:
NotImplementedException() :
        std::logic_error("Function not implemented. Moron.")
        {};
};
