#include "analyzer.hpp"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string function("713a^30 -40 - 122a^2 +150 + 488 - 156426 - 70b   =");

    auto terms = parser::parse(function);

    for (auto i : terms) {
        std::cout << i.op;
        std::cout << i.number;
        std::cout << i.var;
        std::cout << i.exp;
        std::cout << i.degree;
        std::cout << '\n';
    }
    
    return 0;
}
