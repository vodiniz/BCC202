#include <stdbool.h>
#include <math.h>
#define precision 0.01

#ifndef __COMPARE_DOUBLE_H__
#define __COMPARE_DOUBLE_H__

bool approximatelyEqual(double a, double b){
    return fabs(a - b) <= precision;
}

bool definitelyGreaterThan(double a, double b){
    return (a - b) > precision;
}

bool definitelyLessThan(double a, double b){
    return (b - a) > precision;
}

#endif