#include <vector>
#include <iostream>

#include "parser.hpp"
#include "math.hpp"

int main(int argc, char const *argv[])
{
    std::string funStr("x -   x^3 + 4x -10 =");

    auto function = parser::parse(funStr);
    auto derivFn = math::derivate(function);

    math::print(function);
    std::cout << "f(4):\t" << math::solveFor(function, 4) << '\n';
    math::print(derivFn);
    std::cout << "f'(4):\t" << math::solveFor(derivFn, 4) << '\n';
    
    std::cout << "\n";
    return 0;
}
