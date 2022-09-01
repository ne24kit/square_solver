#include <stdio.h>
#include <math.h>
#include "math_utils.h"
#include <assert.h>
#include "solution.h"
#include "user_handling.h"


void solve_equation()
{
    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    int count_sol = NAN;

    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)

    {
        solve_sq_lin(a, b, c, &x1, &x2, &count_sol);

        count_sol_handling(count_sol, x1, x2);

        print_stars();
        print_greetings();
        printf("If you want to end the programme, enter \"q\"\n");

        while(getchar() != '\n');
    }

    printf("You press \"q\" or enter any other non-numeric value and the programme is terminated.\n");
}

void solve_square(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(pcount_sol != NULL);
    assert(px1 != px2);

    double D = (b * b) - (4 * a * c);

    if (!(double_cmp(b, 0))) {

        if (!(double_cmp(c, 0))) {

            if (D > 0) {

                *px1 = (-b + sqrt(D)) / (2 * a);
                *px2 = (-b - sqrt(D)) / (2 * a);
                change_double(px1, px2);
                *pcount_sol = TWO_SOL;

            }

            else if (double_cmp(D, 0)) {

                *px1 = -b / (2 * a);
                *pcount_sol = ONE_SOL;

            }

            else
                *pcount_sol = NO_SOL;
        }

        else {

            *px1 = 0;
            *px2 = -b / a;
            change_double(px1, px2);
            *pcount_sol = TWO_SOL;

        }
    }

    if (double_cmp(b, 0))
        solve_incomplete_quadratic(a, b, c, px1, px2, pcount_sol);
}

void solve_incomplete_quadratic(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(pcount_sol != NULL);
    assert(px1 != px2);

    if (-c / a > 0 && double_cmp(b, 0)) {

        *px1 = -sqrt(-c / a);
        *px2 =  sqrt(-c / a);
        change_double(px1, px2);
        *pcount_sol = TWO_SOL;

    }

    else if (double_cmp(c, 0)) {

        *px1 = 0;
        *pcount_sol = ONE_SOL;

        }

    else
        *pcount_sol = NO_SOL;
}

void solve_lin(double b, double c, double *px1, int *pcount_sol)
{
    assert(px1 != NULL);
    assert(pcount_sol != NULL);

    if (!(double_cmp (b, 0))) {

        *px1 = -c / b;

         if (double_cmp(*px1, 0))
            *px1 = fabs(*px1);

        *pcount_sol = ONE_SOL;

    }

    else if (double_cmp(c, 0))
        *pcount_sol = INF_SOL;

    else
        *pcount_sol = NO_SOL;
}

void solve_sq_lin(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(pcount_sol != NULL);
    assert(px1 != px2);

    if (double_cmp(a, 0))
        solve_lin(b, c, px1, pcount_sol);

    else
        solve_square(a, b, c, px1, px2, pcount_sol);
}
