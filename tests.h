#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

struct tests
{
    double t_a;
    double t_b;
    double t_c;
    int    t_count_sol;
    double t_x1;
    double t_x2;
    // TODO: What is this t_* naming? Delete this obscure and unnecessary prefix!
};

void testing_solver();
//       ^~~ TODO: use imperative

void testing_token_struct(struct tests st[0], int n);
//       ^~~ TODO: use imperative

#endif // TESTS_H_INCLUDED
