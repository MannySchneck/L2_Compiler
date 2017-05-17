#pragma once
#include <L2.h>
#include <deque>
#include <sstream>
#include <exception>
#include <string>
#include <parse_stack.h>

namespace L2{
        Program L2_parse_file (std::string filename);

        Function parse_function_file (std::string fileName);
}


