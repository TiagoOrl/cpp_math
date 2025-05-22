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
                value = std::stoi(term.coeff);

            
            // e.g. x, 12x...
            if (term.var.size() > 0 && term.exp.size() == 0) {

                // e.g. 12x
                if (term.coeff.size() > 0)
                    value = x * std::stoi(term.coeff);

                // e.g. x
                else 
                    value = x;
            }

            // e.g. x^3, 45x^3...
            if (term.exp.size() > 0) {

                // e.g. 45x^3
                if (term.coeff.size() > 0) 
                    value = std::stoi(term.coeff) * (std::pow(x, std::stoi(term.exp)));

                // e.g. x^3
                else
                    value = std::pow(x, std::stoi(term.exp));
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
            if (term.var.size() > 0 && term.exp.size() == 0) {

                // e.g. 12x
                if (term.coeff.size() > 0)
                    derivTerm.coeff = term.coeff; 

                // e.g. x
                else
                    derivTerm.coeff = "1";
            }
            
            // e.g. x^3, 45x^3...
            if (term.exp.size() > 0) {
                derivTerm.var = term.var;
                
                // e.g. 45x^3
                if (term.coeff.size() > 0) {
                    derivTerm.coeff = std::to_string(std::stoi(term.coeff) * std::stoi(term.exp));
                }
                // e.g. x^3
                else {
                    derivTerm.coeff = std::to_string(std::stoi(term.exp));
                }                    

                if (std::stoi(term.exp) > 2) {
                    derivTerm.expOp = "^";
                    derivTerm.exp = std::to_string(std::stoi(term.exp) - 1);
                }   
            }

            derivTerm.rawTerm = derivTerm.op + derivTerm.coeff + derivTerm.var + derivTerm.expOp + derivTerm.exp;
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
            std::cout << i.exp;
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}