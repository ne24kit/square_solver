#include <stdio.h>
#include <math.h>
#include "math_utils.h"
#include "solution.h"
#include "tests.h"
#include "user_handling.h"


void testing_solver()
{
    // TODO: dt? Please, use better naming.
    struct tests dt[] =
    {
        {0,  0,  0, INF_SOL,  NAN,   NAN},
        {1,  2,  1, ONE_SOL,   -1,   NAN},
        {1,  0,  1, NO_SOL ,  NAN,   NAN},
        {0,  2,  0, ONE_SOL,    0,   NAN},
        {0,  2,  2, ONE_SOL,   -1,   NAN},
        {0,  0,  4, NO_SOL ,  NAN,   NAN},
        {1,  1,  1, NO_SOL ,  NAN,   NAN},
        {1, -5,  6, TWO_SOL,    2,     3},
        {5,  0, 10, NO_SOL ,  NAN,   NAN},
        {5,  6,  0, TWO_SOL, -1.2,     0},
        {0,  0,  1, NO_SOL ,  NAN,   NAN}
    };

    // TODO: n? Why not number of tests?
    int n = sizeof(dt)/sizeof(dt[0]);
    //      ^~~~~~~~~~~~~~~~~~~~~~~~ TODO: extract in ARRAY_SIZE macro

    testing_token_struct(&dt[0], n);
}

void testing_token_struct(struct tests st[0], int n)
{   // TODO:                           ^~         ^ TODO: Improve naming!
    // TODO:                              ^ Array of size zero?! Why?

    for (int i = 0; i < n; i++)
    {

        double x1 = NAN, x2 = NAN;
        int count_sol = 0;

        solve_sq_lin(st[i].t_a, st[i].t_b, st[i].t_c, &x1, &x2, &count_sol);

        if (double_NAN_cmp(st[i].t_x1, x1)
            && double_NAN_cmp(st[i].t_x2, x2)
            && st[i].t_count_sol == count_sol)

            printf("TEST %2d IS CORRECT\n", i + 1);
        // TODO:         ^~~ Imagine running a 2000 tests, what would you see?
        // Hmmmmmmmmmmmmm....
        //
        // TEST    1 IS CORRECT
        // TEST    2 IS CORRECT
        // TEST    3 IS CORRECT
        // TEST    4 IS CORRECT
        // TEST    5 IS CORRECT
        // TEST    6 IS CORRECT
        // TEST    7 IS CORRECT
        // TEST    8 IS CORRECT
        // TEST    9 IS CORRECT
        // ... < Imagine here somewhere you had an error. Yeah, it's pretty
        //       much gone in this pile of meaningless and useless text. Don't you think?
        //
        //       Show what's important: actual errors with good descriptions.
        //
        // TEST 1000 IS CORRECT
        // ...


        else {

            print_stars();

            printf("TEST %2d IS FAILED\n", i + 1);

            if (st[i].t_count_sol != count_sol)
                printf("EXPECTED COUNT OF ROOTS: %d\n"
                       "FAILED   COUNT OF ROOTS: %d\n", st[i].t_count_sol, count_sol);

            if (!(double_NAN_cmp(st[i].t_x1, x1)))
            //   ^                              ^ TODO: already commented somewhere, pointless parens
                printf("EXPECTED   FIRST   ROOT: %lg\n"
                       "FAILED     FIRST   ROOT: %lg\n", st[i].t_x1, x1);

            if (!(double_NAN_cmp(st[i].t_x2, x2)))
            //   ^                              ^ TODO: already commented somewhere, pointless parens
                printf("EXPECTED   SECOND  ROOT: %lg\n"
                       "FAILED     SECOND  ROOT: %lg\n", st[i].t_x2, x2);

            print_stars();

        }
    }
}
