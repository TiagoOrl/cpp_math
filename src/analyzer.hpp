#pragma once
#include <string>
#include <vector>


namespace parser {

    struct polynomial {
        std::string value;
        char var;
        char degree;
        char signal;
    };

    bool isOperator(char c) {
        return 
            c == '-' ||
            c == '+';
    }

    bool isExp(char c) {
        return
            c == '^';
    }

    bool isNumber(char c) {
        return 
            c == '0' ||
            c == '1' ||
            c == '2' ||
            c == '3' ||
            c == '4' ||
            c == '5' ||
            c == '6' ||
            c == '7' ||
            c == '8' ||
            c == '9';
    }

    bool isVar(char c) {
        return  
            c == 'x' ||
            c == 'X';
    }


    std::vector<struct polynomial> parse(std::string function) {
        auto size = function.size();
        auto str = function.c_str();
        for (int i = 0; i < size; i++) {
            
        }
    }
    
};