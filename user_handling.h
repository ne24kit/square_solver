#ifndef USER_HANDLING_H_INCLUDED
#define USER_HANDLING_H_INCLUDED
/// Prints a welcome message.
/*!
The function prints this test:

    "Hi, this program solves quadratic equations

    like this: A * x^2 + B * x + C = 0.

    Enter coefficients (A, B, C) as three real numbers."
*/
void print_greetings(void);

/// Prints  60 stars in one line.
void print_stars(void);

/*!
    \brief Outputs to the console screen the number of solutions and the roots of the quadratic equation
    \param count_sol   The number of solutions to the quadratic equation
    \param [out] x1    The root x1 of the quadratic equation
    \param [out] x2    The root x2 of the quadratic equation

*/
void count_sol_handling(int count_sol, double x1, double x2);

#endif // USER_HANDLING_H_INCLUDED
