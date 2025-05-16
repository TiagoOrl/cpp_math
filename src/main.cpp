#include "analyzer.hpp"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string function("-x^5 + x^3 + 45x^2 - x + 177 - 1880 =");

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
