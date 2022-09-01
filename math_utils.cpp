#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "math_utils.h"



bool double_cmp(double m, double n)
{
    const double small_number = 1e-8;
    return fabs(m - n) < small_number;
}

bool double_NAN_cmp(double m, double n)
{
    if ((isnan(m) && isnan(n)))
        return true;

    else if (!(isnan(m)) && !(isnan(n)))
        return double_cmp(m, n);

    else
        return false;
}

void change_double(double *p1, double *p2)
{
    assert(p1 != NULL);
    assert(p2 != NULL);
    assert(p1 != p2);

    double temp = *p1;

    if (*p1 > *p2) {

        *p1 = *p2;
        *p2 = temp;
    }
}
