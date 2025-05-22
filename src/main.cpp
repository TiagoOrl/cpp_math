#include <vector>
#include <iostream>

#include "parser.hpp"
#include "math.hpp"

int main(int argc, char const *argv[])
{
    std::string funStr("3x^7 - 6x^2 + 38x  + 144 =");

    auto function = parser::parse(funStr);
    auto derivFn = math::derivate(function);

    math::print(function);
    std::cout << "f(2) = " << math::solveFor(function, 7) << '\n';
    math::print(derivFn);
    std::cout << "f'(2) = " << math::solveFor(derivFn, 7) << '\n';
    
    std::cout << "\n";
    return 0;
}
