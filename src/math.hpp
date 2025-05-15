#pragma once
#include <string>
#include <iostream>
#include "analyzer.hpp"

namespace math {

    void derivative(std::string function) {
        auto size = function.size();

        for (int i = 0; i < size; i++) {
            std::cout << function.c_str()[i];
        }
    }
}