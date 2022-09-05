#include <stdio.h>
#include <math.h>
#include "math_utils.h"
#include <assert.h>
#include "solution.h"
#include "user_handling.h"

// TODO: This file is the heart of your program, it provides core API
//       (solving equations) that other programmers can potentially
//       integrate in their own programs.

//       Yet, for some reason, you are putting here interactive functions.
//       Do not do this! Split this header in multiple organised by purpose.
//       For example, equation-solver and interactive-equation-solver.

//       Imagine someone with huge project trying to find an equation
//       solver to integrate in his program and stumbling across your GitHub.

//       And then seeing this: to use your library he needs to pollute his
//       project with interactive functions that are pretty much utterly
//       useless there (because no project other than a literal "equation solver"
//       needs a way to interactively input coefficients, but dozens may
//       need to solve equations internally).

//       Make sure interface of every header file stays clean and minimal!

//       Try to maintain a clear separation between core library code
//       and interactive code (that serves as a frontend to it's core part). 

void solve_equation()
{
    double a = NAN, b = NAN, c = NAN;

    // TODO: Move declarations closer to usage
    double x1 = NAN, x2 = NAN;
    int count_sol = NAN;

    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        solve_sq_lin(a, b, c, &x1, &x2, &count_sol);

        count_sol_handling(count_sol, x1, x2);

        print_stars();
        print_greetings();
        printf("If you want to end the programme, enter \"q\"\n");
        // TODO:                              ^~ Mein Gott, spelling maaaaan

        while(getchar() != '\n'); // TODO: this would make a nice function, extract!
    }

    printf("You press \"q\" or enter any other non-numeric value and the programme is terminated.\n");
}

void solve_square(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{
    // What if a, b or c are NAN or INF? Think. Ensure. Document.
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(pcount_sol != NULL);
    assert(px1 != px2);

    // TODO: Do you really need to compute this in all cases (e.g. b = 0)? Waste of time, move closer to usage.
    double D = (b * b) - (4 * a * c);

    if (!(double_cmp(b, 0))) { // TODO: Extract in "is_zero"
    //   ^                ^ TODO: Why put parens here? Doesn't add any clarity, and clutters code

        if (!(double_cmp(c, 0))) { // TODO: Same thing. I guess it can be a "style", but I don't see any pros
            // TODO: This is main course of actions (all non-zero coefficients), I think
            //       if extracting this in function would be a good idea.

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

            else // TODO: Comment that this else implies D < 0 would add clarity 
                *pcount_sol = NO_SOL;
        }

        else {

            *px1 = 0;
            *px2 = -b / a;
            change_double(px1, px2);
            *pcount_sol = TWO_SOL;

        }
    }

    // TODO: Why compare again? Just use else!
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
//                    ^~~~~~~~~~~~~~~~ Why? I thought it's your functions invariant, assert instead (or better
//                                          delete parameter "b" completely (see header for details).
//      ^~~~~~~~~~ TODO: Isn't this the same as c < 0?

        *px1 = -sqrt(-c / a);
        *px2 =  sqrt(-c / a); // TODO: *px1 differs only in sign, why recompute?
        change_double(px1, px2);
        *pcount_sol = TWO_SOL;

        // TODO: Why not early-return from here and delete subsequent "else"'s?
    }

    else if (double_cmp(c, 0)) { // TODO: In your documentation it seemed like you can only pass b = 0
                                 //       So, I think, it's your ax^2 = 0? But!

        *px1 = 0;
        *pcount_sol = ONE_SOL;

        }
    //  ^ TODO: misaligned

    else // TODO: comment what case this is (E.g. else /* ax^2 = - c, c > 0 */). I would go as far
         //       as to add such descriptions to every "if" as it helps to follow you're code.
         //       But I will not require it. Think if it's worth it from your perspective!
        *pcount_sol = NO_SOL;
}

void solve_lin(double b, double c, double *px1, int *pcount_sol)
{ // TODO: ^~~ Don't use obscure abbrevations
    assert(px1 != NULL);
    assert(pcount_sol != NULL);

    if (!(double_cmp (b, 0))) { // TODO: extract in "is_zero"

        *px1 = -c / b;

        if (double_cmp(*px1, 0))
            *px1 = fabs(*px1);
        // TODO:   ^~~~ Why not just *px1 = 0.0? Would be much faster!

        *pcount_sol = ONE_SOL;

    }

    else if (double_cmp(c, 0)) // TODO: extract in "is_zero"
        *pcount_sol = INF_SOL;

    else
        *pcount_sol = NO_SOL;
}

void solve_sq_lin(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{ // TODO: ^~ ^~~ Naming! What is "sq" "lin". I guess solve_square_linear,
  // but what does that mean? That it solves both? Not obvious!
    assert(px1 != NULL);
    assert(px2 != NULL);
    assert(pcount_sol != NULL);
    assert(px1 != px2);
    // TODO: what if pcount_sol is equal to px1 or px2?

    if (double_cmp(a, 0))
        solve_lin(b, c, px1, pcount_sol);

    else
        solve_square(a, b, c, px1, px2, pcount_sol);
}
