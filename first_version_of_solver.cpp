#include <stdio.h>
#include <TXLib.h>
#include <math.h>
void solve(double a, double b, double c);
void hi(void);
void stars(void);
int main(void)
{
    hi();

    double a = 0, b = 0, c = 0;

    while((scanf("%lf", &a) == 1) && (scanf("%lf", &b) == 1) && (scanf("%lf", &c) == 1))
    {
        solve(a, b, c);

        stars();
        hi();
        printf("Если вы хотите завершить программу введите \"q\"\n");
    }
}
void solve(double a, double b, double c)
{
    double D = b*b - 4*a*c;

    if (a != 0) {
        if (b != 0) {
            if (c != 0) {
                if (D>0)
                    printf("x1 = %lf, x2 = %lf\n", (-b + sqrt(D))/(2*a), (-b - sqrt(D))/(2*a));
                else if (D == 0)
                    printf("x = %lf\n", -b/(2*a));
                else if (D < 0)
                    printf("Нет решений\n");
            }
            else
                printf("x1 = 0, x2 = %lf\n", -b/a);
        }
        else if (-c/a>0)
            printf("x1 = %lf, x2 = %lf\n", sqrt(-c/a), -sqrt(-c/a));
        else if (c == 0)
            printf("x = 0\n");
        else
            printf("Нет решений\n");
    }

    if (a == 0) {
        if (b != 0) {
            if (c != 0)
                printf("x = %lf\n", -c/b);
            else
                printf("x = 0\n");
        }
        else if (c == 0)
            printf("Бесконечно много корней\n");
        else
            printf("Нет корней\n");

    }
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
