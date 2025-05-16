#include <iostream>
#include "analyzer.hpp"
#include "helper/print.hpp"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string function("     +488x^30 - 15487x^42 +150=");

    auto pols = parser::parse(function);

    for (auto i : pols) {
        std::cout << i.op;
        std::cout << i.number;
        std::cout << i.var;
        std::cout << i.exp;
        std::cout << i.degree;
        std::cout << " ";
    }
    
    return 0;
}
