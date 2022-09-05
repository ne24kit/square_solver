#ifndef MATH_UTILS_H_INCLUDED
#define MATH_UTILS_H_INCLUDED

/// A set of possible counts of roots
enum eSol
{ // ^~~~ What is "e"? TODO: Use better naming, avoid abbrivations (especially obscure ones)
    NO_SOL , ///< No roots
    ONE_SOL, ///< One root
    TWO_SOL, ///< Two roots
    INF_SOL  ///< Infinitely many roots
    //  ^~~ TODO: Why not write word "solutions" fully? It adds clarity. And remember,
    //            your enum values are in global scope. Naming global scope stuff
    //            is especially important, since it doesn't have a context of, well, scope.
};

/*!
    \brief Can safely compare two numbers of type double
    \param m, n Comparable numbers
    \return True if two numbers are equal to a certain accuracy, or false if they are not

*/
// TODO: Comparators (as suggested by name "cmp") usually return int:
//           -1 (or any negative) if first parameter is less than second
//            0 (exactly)         if they are equal
//           +1 (or any positive) if first parameter is greater than second
//
//       But your function is more of a are_equal(double x, double y), than
//       compare(double x, double y). Do you see it?
bool double_cmp(double m, double n);
//   ^~~~~~~ TODO: This kind of naming is useful in C, but useless in C++ (because
//                 C++ allows you to have multiple functions with the same name
//                 but different parameters), for example:
//
//           bool compare(double a, double b); 
//           bool compare(float  a, float  b);
//
//           Is valid in C++, but not in C (compiler will report double definition),
//           meanwhile C++ will choose target definition upon calling at compile time
//           thus allowing multiple functions to share same name.
//
//           How does he do it? It essentially does same thing you did (adds names of
//           parameters types to functions internal name, which is unique and is used
//           by linker to link function calls and declarations within different object files)
//
//           In general this behaviour is called polymorphism (overloading to be more specific,
//           as there is 4 kinds of polymorphism, and 3 other ones are definitely go beyond
//           this course).
//
//           This "TODO" isn't really "need to fix". I'm not sure if DED even allows
//           you to use polymorphic behaviour in C++ (I guess he does if you understand
//           how it works). It's just something to think about and use, if you like it.
//
//           Note, if this would be a C++ course I would tell you to delete "double"
//           from functions name :) But it's not, so you decide!

// TODO: Seems pretty natural to me that double_cmp would return 0 if both parameters are NAN.
//       Maybe you should rename this function to just "double_cmp" and than make current
//       "double_cmp" that doesn't recognize NAN's a static function in math_utils.cpp,
//       because i don't really see a use for it (when you have this).
//
//       Also, NAN in the name doesn't really work (I had too check implementation before I knew
//       why it's even there).
bool double_NAN_cmp(double m, double n);

/*!
    \brief Swaps pointer values if the first pointer value is greater than the second
    \details If the value of pointer p1 is greater than p2,

    the function assigns the smaller value to pointer p1 and the larger value to pointer p2.

    \param p1, p2 Pointers to exchange in a particular case
*/
void change_double(double *p1, double *p2);
//   ^~~~~~~ TODO: "Change" is generic as f*ck for such niche function.
//                 It surely does "change double", but it's like calling:
//                 function "function":

//                 void function_that_does_stuff(...);

//                 Like yeah, it's true, but it doesn't actually mean anything!
//                 Same logic applies here. Name should not only be "true", it
//                 should be descriptive and actually useful. It shall be a brief
//                 description of function's functionality.

//                 Always think: can you guess function's purpose by name alone?
//                 If not, rename it. It's that simple.

#endif // MATH_UTILS_H_INCLUDED
