#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>
#include <regex>
#include "term.h"


class Function
{
    public:
    explicit Function(const std::string& f);
    const std::string& getFuncStr() const;

    private:
    std::string func_str = "";
    std::vector<Term> polynomial;
};


#endif
