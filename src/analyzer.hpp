#pragma once
#include <string>
#include <vector>


namespace parser {

    struct term {
        std::string number;
        char var;
        std::string degree;
        char exp;
        char op;
    };

    int pos = 0;
    bool polynomialStart = true;
    bool expectNumber = false;
    bool expectNumberDegree = false;
    bool expectOp = false;
    bool expectExpSymbol = false;
    bool expectVar = false;

    
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


    bool isEquals(char c) {
        return c == '=';
    }


    void handleNumber(term &pol, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            pol.number += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;
                
            pos++;
        }
    }

    void handleNumberDegree(term &pol, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            pol.degree += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;

            pos++;
        }
    }

    void handleVar(term &pol, std::string fn, int &pos) {
        pol.var = fn.at(pos);
    }

    void handleExpSymbol(term &pol, std::string fn, int &pos) {
        pol.exp = fn.at(pos);
    }

    
    void handleOperator(term &pol, std::string fn, int &pos) {
        pol.op = fn.at(pos);
    }

    void resetState() {
        polynomialStart = true;
        expectNumber = false;
        expectNumberDegree = false;
        expectOp = false;
        expectExpSymbol = false;
        expectVar = false;
    }

    std::vector<struct term> parse(std::string fn) {
        term pol = {};
        std::vector<struct term> terms;


        while (pos < fn.size()) {
            if (isWhitespace(fn.at(pos))) {
                pos++;
                continue;
            }

            if (polynomialStart) {
                if (isOperator(fn.at(pos))) {
                    handleOperator(pol, fn, pos);
                    expectNumber = true;
                }

                else if (isNumber(fn.at(pos))) {
                    handleNumber(pol, fn, pos);
                    pol.op = '+';
                    expectVar = true;
                }

                else if (isVar(fn.at(pos))) {
                    handleVar(pol, fn, pos);
                    expectExpSymbol = true;
                }   

                polynomialStart = false; 
            } 

            else {
                if (expectNumber) {
                    handleNumber(pol, fn, pos);
                    expectNumber = false;
                    expectVar = true;
                }

                else if (expectExpSymbol) {
                    handleExpSymbol(pol, fn, pos);
                    expectExpSymbol = false;
                    expectNumberDegree = true;
                }

                else if (expectVar) {
                    handleVar(pol, fn, pos);
                    expectVar = false;
                    expectExpSymbol = true;
                }

                else if (expectNumberDegree) {
                    handleNumberDegree(pol, fn, pos);
                    expectNumberDegree = false;
                    polynomialStart = true;
                    terms.push_back(pol);
                    resetState();
                    pol = {};
                }


                if (isEquals(fn.at(pos))) {
                    terms.push_back(pol);
                    resetState();
                    pol = {};
                }
            }

            pos++;
        }

        return terms;
    }
    
};