#include <iostream>
#include "math.hpp"
#include "analyzer.hpp"
#include "helper/print.hpp"

int main(int argc, char const *argv[])
{
    if (parser::isOperator('*'))
        println("is valid op");
    else 
        println("is not valid op symbol");
    
    return 0;
}
