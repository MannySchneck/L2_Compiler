#pragma once

#include <marker_classes.h>
#include <instruction.h>
#include <labels.h>
#include <algorithm>

using namespace L2;

class Jump{
public:
        Inst_Posn find_target(std::vector<Inst_Ptr>::iterator begin,
                              std::vector<Inst_Ptr>::iterator end,
                              const L2_Label &lab);
};
