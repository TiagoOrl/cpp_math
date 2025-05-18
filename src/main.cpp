#include <vector>
#include <iostream>

#include "parser.hpp"
#include "math.hpp"

int main(int argc, char const *argv[])
{
    std::string funStr("-50x^6 -x^7 - x^3 +45x^2 + 480x +x -1880  =");

    auto function = parser::parse(funStr);
    auto derivFn = math::derivate(function);

    std::cout << "function:\t";
    for (auto i : function) {
        std::cout << i.op;
        std::cout << i.coeff;
        std::cout << i.var;
        std::cout << i.expOp;
        std::cout << i.exp;
        std::cout << ' ';
    }

    std::cout << "\nderiv function:\t";
    for (auto i : derivFn) {
        std::cout << i.op;
        std::cout << i.coeff;
        std::cout << i.var;
        std::cout << i.expOp;
        std::cout << i.exp;
        std::cout << ' ';
    }
    std::cout << "\n";
    return 0;
}
