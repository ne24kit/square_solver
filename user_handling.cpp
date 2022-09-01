#include <stdio.h>
#include <assert.h>
#include "math_utils.h"
#include "user_handling.h"

void print_greetings(void)
{
    printf("Hi, this program solves quadratic equations\n");
    printf("like this: A * x^2 + B * x + C = 0.\n");
    printf("Enter coefficients (A, B, C) as three real numbers\n");
}

void print_stars(void)
{
    int const limit = 60;
    for (int i = 0; i < limit; i++)
        printf("*");
    printf("\n");
}

void count_sol_handling(int count_sol, double x1, double x2)
{
    switch (count_sol)
    {
        case INF_SOL:
               printf("Infinitely many roots\n");
               break;

        case TWO_SOL:
               printf("Two roots:\n");
               printf("x1 = %lg\n", x1);
               printf("x2 = %lg\n", x2);
               break;

        case ONE_SOL:
               printf("One root:\n");
               printf("x1 = %lg\n", x1);
               break;

        case NO_SOL :
               printf("No roots\n");
               break;

        default:
               assert(false && "Oops, something has gone wrong. Illegal number of roots\n");
    }
}
