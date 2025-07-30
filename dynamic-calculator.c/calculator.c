#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

double add( double addend_a, double addend_b){
    return addend_a + addend_b;
}

double subtract(double minuend, double subtrahend){
    return minuend - subtrahend;
}

double multiply(double factor_a, double factor_b){
    return factor_a * factor_b;
}

double divide(double dividend, double divisor ){
    return dividend / divisor;
}