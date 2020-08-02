#include <stdio.h>
#include <math.h>

double fun(double eps)
{
    double pi = 0.0, up = 1.0, down = 1.0, unit = (double)up / (double)down;
    int count = 1;
    while (unit >= eps)
    {
        pi += unit;
        up *= count;
        down *= 2 * count + 1;
        unit = (double)up / (double)down;
        count++;
    }

    return pi * 2;
}

int main(int argc, char const *argv[])
{
    printf("Input eps:");
    double x;
    scanf("%lf", &x);
    printf("\neps = %lf, PI = %lf\n", x, fun(x));

    return 0;
}
