#pragma once
#include "parser.hpp"

namespace math {

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
}