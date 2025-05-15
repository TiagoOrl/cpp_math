#pragma once
#include <string>
#include <vector>


namespace parser {

    struct polynomial {
        std::string number;
        char var;
        char degree;
        char exp;
        char op;
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


    bool isWhitespace(char c) {
        return c == ' ';
    }


    void handleNumber(polynomial &pol, std::string fn, int &pos) {
        while(isNumber(fn.at(pos))) {
            pol.number += fn.at(pos);
            pos++;
        }
    }

    void handleVar(polynomial &pol, std::string fn, int &pos) {
        pol.var = fn.at(pos);
        if (pos < fn.size())
            pos++;
    }

    void handleExpSymbol(polynomial &pol, std::string fn, int &pos) {
        pol.exp = fn.at(pos);
        if (pos < fn.size())
            pos++;
    }

    
    void handleOperator(polynomial &pol, std::string fn, int &pos) {
        pol.op = fn.at(pos);
        if (pos < fn.size())
            pos++;
    }



    std::vector<struct polynomial> parse(std::string fn) {
        polynomial pol;
        int pos = 0;
        int peek = 0;
        bool polynomialStart = true;
        bool expectNumber = false;
        bool expectOp = false;
        bool expectExpSymbol = false;
        bool expectVar = false;

        pol.number = "";

        while (pos < fn.size()) {
            if (isWhitespace(fn.at(pos))) {
                pos++;
                continue;
            }

            if (polynomialStart) {
                if (isNumber(fn.at(pos))) {
                    handleNumber(pol, fn, pos);
                    expectVar = true;
                }

                if (isVar(fn.at(pos))) {
                    handleVar(pol, fn, pos);
                    expectExpSymbol = true;
                }   

                if (isOperator(fn.at(pos))) {
                    handleOperator(pol, fn, pos);
                    expectNumber = true;
                }

                polynomialStart = false; 
            }


            
            pos++;
        }
    }
    
};