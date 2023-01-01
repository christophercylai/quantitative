#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include "term.h"


class Function
{
    public:
    explicit Function(const std::string& f);
    const std::string& getFuncStr();

    private:
    std::string func_str = "";
    std::vector<Term> polynomial;
};


#endif
