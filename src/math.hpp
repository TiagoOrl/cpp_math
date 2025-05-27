#pragma once
#include "parser.hpp"
#include <cmath>

namespace math {
    long solveFor(std::vector<parser::term> function, int x);
    bool containsRoot(std::vector<parser::term> fn, int start);
    void print(std::vector<parser::term> fn);

    void plotRange(std::vector<parser::term> fn, int from, int to) {
        print(fn);
        for (int i = from; i <= to; i++) {

            if (containsRoot(fn, i))
                std::cout << "f(" << i << ") = " << solveFor(fn, i) << " close root" << '\n';
            else
                std::cout << "f(" << i << ") = " << solveFor(fn, i) << '\n';
        }
    }


    bool containsRoot(std::vector<parser::term> fn, int start) {
        long a = solveFor(fn, start);
        long b = solveFor(fn, start + 1);


        if (std::signbit(a) != std::signbit(b))
            return true;

        return false;
    }


    std::vector<std::vector<int>> aproxRootsByRange(std::vector<parser::term> fn, int from, int to) {
        std::vector<std::vector<int>> pairs;

        for (int i = from; i < to; i++) {
            if (containsRoot(fn, i))
                pairs.push_back(std::vector{i , i + 1});
        }

        return pairs;
    }

    void printRootsAprox(std::vector<parser::term> fn, int from, int to) {
        print(fn);
        auto roots = aproxRootsByRange(fn, from, to);
        for (auto i : roots) {
            std::cout << "range found: " << i.at(0) << " " << i.at(1) << '\n';
        }
    }


    long solveFor(std::vector<parser::term> function, int x) {
       long sum = 0;
       long value;
       
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
        std::cout << "f(x):\t";
        for (auto i : fn) {
            std::cout << i.op;
            if (i.coeff != 0)
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