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
    bool termStart = true;
    bool expectNumber = false;
    bool expectExpDegree = false;
    bool expectExpOrOp = false;
    bool expectVar = false;

    
    bool isOperator(char c) {
        return 
            c == '-' ||
            c == '+';
    }

    bool isExpOp(char c) {
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
            c == 'a' ||
            c == 'b' ||
            c == 'c' ||
            c == 'd' ||
            c == 'e' ||
            c == 'f' ||
            c == 'g';
    }


    bool isWhitespace(char c) {
        return c == ' ';
    }


    bool isEquals(char c) {
        return c == '=';
    }


    void handleNumber(term &term, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            term.number += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;
                
            pos++;
        }
    }

    void handleNumberDegree(term &term, std::string fn, int &pos) {
        while(isNumber(fn.at(pos)) && pos < fn.size()) {
            term.degree += fn.at(pos);
            if (!isNumber(fn.at(pos + 1)))
                break;

            pos++;
        }
    }

    void handleVar(term &term, std::string fn, int &pos) {
        term.var = fn.at(pos);
    }

    void handleExpSymbol(term &term, std::string fn, int &pos) {
        term.exp = fn.at(pos);
    }

    
    void handleOperator(term &term, std::string fn, int &pos) {
        term.op = fn.at(pos);
    }

    void resetState() {
        termStart = true;
        expectNumber = false;
        expectExpDegree = false;
        expectExpOrOp = false;
        expectVar = false;
    }

    std::vector<struct term> parse(std::string fn) {
        term term = {};
        std::vector<struct term> terms;


        while (pos < fn.size()) {
            if (isEquals(fn.at(pos))) {
                terms.push_back(term);
                resetState();
                term = {};
                break;
            }

            if (isWhitespace(fn.at(pos))) {
                pos++;
                continue;
            }

            if (termStart) {
                if (isOperator(fn.at(pos))) {
                    handleOperator(term, fn, pos);
                    expectNumber = true;
                }

                else if (isNumber(fn.at(pos))) {
                    handleNumber(term, fn, pos);
                    term.op = '+';
                    expectVar = true;
                }

                else if (isVar(fn.at(pos))) {
                    handleVar(term, fn, pos);
                    expectExpOrOp = true;
                }   

                termStart = false; 
            } 

            else {
                if (expectNumber) {
                    handleNumber(term, fn, pos);
                    expectNumber = false;
                    expectVar = true;
                }

                else if (expectExpOrOp) {
                    if (isExpOp(fn.at(pos))) {
                        handleExpSymbol(term, fn, pos);
                        expectExpDegree = true;
                        expectExpOrOp = false;
                    }

                    else {
                        termStart = true;
                        terms.push_back(term);
                        resetState();
                        term = {};
                    }
                }

                else if (expectVar) {
                    handleVar(term, fn, pos);
                    expectVar = false;
                    expectExpOrOp = true;
                }

                else if (expectExpDegree) {
                    handleNumberDegree(term, fn, pos);
                    expectExpDegree = false;
                    termStart = true;
                    terms.push_back(term);
                    resetState();
                    term = {};
                }
            }

            pos++;
        }

        return terms;
    }
    
};