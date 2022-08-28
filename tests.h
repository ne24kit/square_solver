#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include "solution.h"
#include "math_utils.h"

///
struct test
{
    double t_a;
    double t_b;
    double t_c;
    int    t_count_sol;
    double t_x1;
    double t_x2;
};

struct data_tests
{
    struct test example;
};

void testing_solver();

void testing_token_struct(struct data_tests st[0], int n);


#endif // TESTS_H_INCLUDED
