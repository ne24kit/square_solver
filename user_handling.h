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
// TODO:         ^~~~~ consider passing number of stars to print...

/*!
    \brief Outputs to the console screen the number of solutions and the roots of the quadratic equation
    \param count_sol   The number of solutions to the quadratic equation
    \param [out] x1    The root x1 of the quadratic equation
    \param [out] x2    The root x2 of the quadratic equation

*/
void count_sol_handling(int count_sol, double x1, double x2);
//   ^~~~~ TODO: I'm still not satisfied with name! Does it count? No!
//               (And if it did I would expect it to return integer)
//
//               And handling is still to "generic", you can describe anything
//               with it. I would go as far as telling you that function in general is: 
//
//               type handle_parameters(...); So your name doesn't add any clarity!

#endif // USER_HANDLING_H_INCLUDED
