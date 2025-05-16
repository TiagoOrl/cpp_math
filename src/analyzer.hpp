#pragma once
#include <string>
#include <vector>


namespace parser {

    struct polynomial {
        std::string number;
        char var;
        std::string degree;
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


    bool isEquals(char c) {
        return c == '=';
    }


    void handleNumber(polynomial &pol, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            pol.number += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;
                
            pos++;
        }
    }

    void handleNumberDegree(polynomial &pol, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            pol.degree += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;

            pos++;
        }
    }

    void handleVar(polynomial &pol, std::string fn, int &pos) {
        pol.var = fn.at(pos);
    }

    void handleExpSymbol(polynomial &pol, std::string fn, int &pos) {
        pol.exp = fn.at(pos);
    }

    
    void handleOperator(polynomial &pol, std::string fn, int &pos) {
        pol.op = fn.at(pos);
    }



    std::vector<struct polynomial> parse(std::string fn) {
        polynomial pol = {};
        std::vector<struct polynomial> polynomials;

        int pos = 0;
        bool polynomialStart = true;
        bool expectNumber = false;
        bool expectNumberDegree = false;
        bool expectOp = false;
        bool expectExpSymbol = false;
        bool expectVar = false;


        while (pos < fn.size()) {
            if (isWhitespace(fn.at(pos))) {
                pos++;
                continue;
            }

            if (polynomialStart) {
                if (isOperator(fn.at(pos))) {
                    handleOperator(pol, fn, pos);
                    expectNumber = true;
                    pos++;
                    polynomialStart = false; 
                    continue;
                }

                else if (isNumber(fn.at(pos))) {
                    handleNumber(pol, fn, pos);
                    expectVar = true;
                    pos++;
                    polynomialStart = false; 
                    continue;
                }

                else if (isVar(fn.at(pos))) {
                    handleVar(pol, fn, pos);
                    expectExpSymbol = true;
                    pos++;
                    polynomialStart = false; 
                    continue;
                }   
            }

            
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
                polynomials.push_back(pol);
                pol = {};
            }


            if (isEquals(fn.at(pos))) {
                polynomials.push_back(pol);
                pol = {};
            }
            
            pos++;
        }

        return polynomials;
    }
    
};