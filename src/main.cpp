#include <iostream>
#include "analyzer.hpp"
#include "helper/print.hpp"
#include <vector>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::string function("713x^30 +40x^8 - 122x^7 +150=");

    auto terms = parser::parse(function);

    for (auto i : terms) {
        std::cout << i.op;
        std::cout << i.number;
        std::cout << i.var;
        std::cout << i.exp;
        std::cout << i.degree;
        std::cout << " ";
    }
    std::cout << '\n';
    
    return 0;
}
