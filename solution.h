#ifndef SOLUTION_H_INCLUDED
#define SOLUTION_H_INCLUDED

/*!
    \brief This function organises the entry of the coefficients a, b and c of a square equation from the console
    \details Contains a loop that includes functions:
    TODO:    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Why does your user need to know this?

        solve_sq_lin, count_sol_handling, print_stars, print_greetings

*/
void solve_equation();

/*!
    \brief Transmits coefficients, pointers to roots and pointer to number of roots
    TODO:  ^~~~~~~~~ Transmits?! Too generic and obscure! Use more descriptive words like "solve"
    \details Also passes the required coefficients depending on the coefficient a to these functions:

        solve_square, solve_lin, double_cmp
*/
void solve_sq_lin(double a, double b, double c, double *px1, double *px2, int *pcount_sol);

/*!
    \brief Solves a complete quadratic equation.
    \details Changes the values of the roots and their number using pointers to them
    \details Contains these functions:
    TODO:    ^~~~~~~~~~~~~~~~~~~~~~~~ Why does your user need to know this?

        double_cmp, change_double, solve_incomplete_quadratic
    \param [in]  a            The coefficient A of the quadratic equation  A * x^2 + B * x + C = 0
    \param [in]  b            The coefficient B of the quadratic equation  A * x^2 + B * x + C = 0
    \param [in]  c            The coefficient C of the quadratic equation  A * x^2 + B * x + C = 0
    \param [out] px1          Pointer to the root x1 of the quadratic equation
    \param [out] px2          Pointer to the root x2 of the quadratic equation
    \param pcount_sol         Pointer to the number of solutions to the quadratic equation

*/
void solve_square(double a, double b, double c, double *px1, double *px2, int *pcount_sol);

/*!
    \brief Solves incomplete quadratic equations
    TODO:         ^~~~~~~~~~ Add descrition, what does that mean?
    \details Changes the values of the roots and their number using pointers to them
    \details Contains these functions:
    TODO:    ^~~~~~~~~~~~~~~~~~~~~~~~ Why does your user need to know this?

        double_cmp, change_double
    \param [in]  a            The coefficient A of the incomplete quadratic equation A * x^2 + C = 0
    \param [in]  b            The coefficient B(= 0) of the incomplete quadratic equation  A * x^2 + C = 0
    TODO                                      ^~~~~~ Why pass parameter if it can have only one value?
    \param [in]  c            The coefficient C of the incomplete quadratic equation  A * x^2 + C = 0
    \param [out] px1          Pointer to the root x1 of the incomplete quadratic equation
    \param [out] px2          Pointer to the root x2 of the incomplete quadratic equation
    \param pcount_sol         Pointer to the number of solutions to incomplete quadratic equation
*/
void solve_incomplete_quadratic(double a, double b, double c, double *px1, double *px2, int *pcount_sol);

/*!
    \brief Solves linear equations
    TODO:       ^ Using imperative in documentations is considered good practice e.g. Solve linear...
    \details Changes the values of the roots and their number using pointers to them
    TODO:    ^~~~~~~ You already specified "out" parameters, obvious.
    \details Contains this function:
    TODO:    ^~~~~~~~~~~~~~~~~~~~~~~ Why put this in documentation?

        double_cmp
    \param [in]  b            The coefficient B of the linear equation  B * x + C = 0
    \param [in]  c            The coefficient C of the linear equation  B * x + C = 0
    \param [out] px1          Pointer to the root x1 of the linear equation
    \param pcount_sol         Pointer to the number of solutions to the linear equation

*/
void solve_lin(double b, double c, double *px1, int *pcount_sol);

#endif // SOLUTION_H_INCLUDED
