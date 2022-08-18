#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void solve_sq(double a, double b, double c, double *px1, double *px2, int *pcount_sol);
void solve_lin(double b, double c, double *px1, int *pcount_sol);
void hi(void);
void stars(void);
int main(void)
{
    hi();

    double a = 0, b = 0, c = 0;

    double x1 = 0, x2 = 0;

    int count_sol = -1;

    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if (a != 0)
            solve_sq(a, b, c, &x1, &x2, &count_sol);
        else
            solve_lin(b, c, &x1, &count_sol);
        if (count_sol == 3)
            printf("Бесконечно много корней\n");
        else if (count_sol == 2) {
            printf("Два решения:\n");
            printf("x1 = %g\n", x1);
            printf("x2 = %g\n", x2);
        }
        else if (count_sol == 1)  {
            printf("Один корень:\n");
            printf("x1 = %g\n", x1);
        }
        else
            printf("Нет решений\n");

        stars();
        hi();
        printf("Если вы хотите завершить программу введите \"q\"\n");
    }
    printf("Вы нажали \"q\" или ввели любое другое нечисловое значение и программа завершилась");
    return 0;
}
void solve_sq(double a, double b, double c, double *px1, double *px2, int *pcount_sol)
{
    double D = b*b - 4*a*c;
    if (b != 0) {
        if (c != 0) {
            if (D>0) {
                *px1 = (-b + sqrt(D)) / (2 * a);
                *px2 = (-b - sqrt(D)) / (2 * a);
                *pcount_sol = 2;
            }
            else if (D == 0) {
                *px1 = -b / (2 * a);
                *pcount_sol = 1;
            }
            else
                *pcount_sol = 0;
        }
        else {
            *px1 = 0;
            *px2 = -b / a;
            *pcount_sol = 2;
        }
    }
    else if (-c / a > 0) {
        *px1 = sqrt(-c / a);
        *px2 = -sqrt(-c / a);
        *pcount_sol = 2;
    }
    else if (c == 0) {
        *px1 = 0;
        *pcount_sol = 1;
        }
    else
        *pcount_sol = 0;
}

void solve_lin(double b, double c, double *px1, int *pcount_sol)
{
    if (b != 0) {
        *px1 = -c / b;
        *pcount_sol = 1;
    }
    else if (c == 0)
        *pcount_sol = 3;
    else
        *pcount_sol = 0;
}

void hi(void)
{
    printf("Привет, это программа решает квадратные уравнения\n");
    printf("такого вида: A * x^2 + B * x + C = 0\n");
    printf("Введите коэффиценты(A, B, C) в виде трёх действительных чисел\n");
}
void stars(void)
{
    for (int i = 1; i < 60; i++)
        printf("*");
    printf("\n");
}
