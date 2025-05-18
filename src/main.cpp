#include <vector>
#include <iostream>

#include "parser.hpp"
#include "math.hpp"

int main(int argc, char const *argv[])
{
    std::string funStr("-50x^6 -x^7 - x^3 +45x^2 + 480x +x -1880  =");

    auto function = parser::parse(funStr);
    auto derivFn = math::derivate(function);

    math::print(function);
    math::print(derivFn);
    math::print(math::derivate(derivFn));
    std::cout << "\n";
    return 0;
}
