#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

// function that adds two values together then returns the result
double add(double addend_a, double addend_b){ 
    return addend_a + addend_b;
}
// function that subtracts two values then returns the result
double subtract(double minuend, double subtrahend){
    return minuend - subtrahend;
}
// function that multiplies two values and returns the result
double multiply(double factor_a, double factor_b){
    return factor_a * factor_b;
}
// function that divides two values and returns the result
double divide(double dividend, double divisor ){
    return dividend / divisor;
}