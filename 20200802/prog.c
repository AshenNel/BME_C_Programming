#include <stdio.h>
#include <math.h>

double fun(double eps)
{
    ;
}

int main(int argc, char const *argv[])
{
    printf("Input eps:");
    double x;
    scanf("%lf", &x);
    printf("\neps = %lf, PI = %lf\n", x, fun(x));

    return 0;
}
