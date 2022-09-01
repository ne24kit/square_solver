#ifndef MATH_UTILS_H_INCLUDED
#define MATH_UTILS_H_INCLUDED

/// A set of possible counts of roots
enum eSol
{
    NO_SOL , ///< No roots
    ONE_SOL, ///< One root
    TWO_SOL, ///< Two roots
    INF_SOL  ///< Infinitely many roots
};

/*!
    \brief Can safely compare two numbers of type double
    \param m, n Comparable numbers
    \return True if two numbers are equal to a certain accuracy, or false if they are not

*/
bool double_cmp(double m, double n);

bool double_NAN_cmp(double m, double n);

/*!
    \brief Swaps pointer values if the first pointer value is greater than the second
    \details If the value of pointer p1 is greater than p2,

    the function assigns the smaller value to pointer p1 and the larger value to pointer p2.

    \param p1, p2 Pointers to exchange in a particular case
*/
void change_double(double *p1, double *p2);

#endif // MATH_UTILS_H_INCLUDED
