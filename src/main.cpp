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

    math::print(function);
    math::print(derivFn);

    math::plotRange(derivFn, from, to);

    auto roots = math::findRoots(derivFn, from, to, 10);
    
    std::cout << "roots:\n";
    for (auto i : roots) {
        std::cout << i << '\n';
    }

    
    std::cout << "\n";
    return 0;
}
