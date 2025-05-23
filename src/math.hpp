#pragma once
#include "parser.hpp"
#include <cmath>

namespace math {


    int solveFor(std::vector<parser::term> function, int x) {
       int sum = 0;
       int value;
       
        for (auto term : function) {
            value = 0;

            // e.g. constant
            if (term.var.size() == 0)
                value = term.coeff;

            
            // e.g. x, 12x...
            if (term.var.size() > 0 && term.exp == 1) {

                // e.g. 12x
                if (term.coeff != 0)
                    value = x * term.coeff;

                // e.g. x
                else 
                    value = x;
            }

            // e.g. x^3, 45x^3...
            if (term.exp != 1) {

                // e.g. 45x^3
                if (term.coeff != 0) 
                    value = term.coeff * (std::pow(x, term.exp));

                // e.g. x^3
                else
                    value = std::pow(x, term.exp);
            }

            if (term.op == "-")
                value = -value;

            sum += value;
        }

        return sum;
    }

    std::vector<parser::term> derivate(std::vector<parser::term> function) {
        std::vector<parser::term> derivFunction;
        for (auto term : function) {
            parser::term derivTerm = {};

            // e.g. constant
            if (term.var.size() == 0)
                continue;
            
            derivTerm.op = term.op;

                // e.g. x, 12x...
            if (term.var.size() > 0 && term.exp == 1) {

                // e.g. 12x
                if (term.coeff != 0)
                    derivTerm.coeff = term.coeff; 

                // e.g. x
                else
                    derivTerm.coeff = 1;
            }
            
            // e.g. x^3, 45x^3...
            if (term.exp != 1) {
                derivTerm.var = term.var;
                
                // e.g. 45x^3
                if (term.coeff != 0) {
                    derivTerm.coeff = term.coeff * term.exp;
                }
                // e.g. x^3
                else {
                    derivTerm.coeff = term.exp;
                }                    

                if (term.exp > 2) {
                    derivTerm.expOp = "^";
                    derivTerm.exp = term.exp - 1;
                }   
            }

            derivFunction.push_back(derivTerm);
        }

        return derivFunction;
    }


    void print(std::vector<parser::term> fn) {
        std::cout << "function:\t";
        for (auto i : fn) {
            std::cout << i.op;
            std::cout << i.coeff;
            std::cout << i.var;
            std::cout << i.expOp;
            if (i.exp != 1)
                std::cout << i.exp;
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}