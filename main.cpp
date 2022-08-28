#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "solution.h"
#include "user_handling.h"
#include "tests.h"

int main()
{
    testing_solver();

    print_greetings();

    solve_equation();

    return 0;
}
