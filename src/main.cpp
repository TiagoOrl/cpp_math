#include <vector>
#include <iostream>

#include "parser.hpp"
#include "math.hpp"

int main(int argc, char const *argv[])
{
    std::string funStr("2x^4  -30x^2 + 48x - 150 =");

    auto function = parser::parse(funStr);
    auto derivFn = math::derivate(function);
    int from = -20;
    int to = 20;

    math::plotRange(function, from, to);
    math::printRootsAprox(function, from, to);

    math::plotRange(derivFn, from, to);
    math::printRootsAprox(derivFn, from, to);
    
    std::cout << "\n";
    return 0;
}
