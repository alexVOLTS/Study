#include <stdio.h>
#include <locale.h>
#include <float.h>

double x;

int calculate(void)
{
    printf("\nInput number with double type: ");
    scanf("%lf", &x);

    x = x * x * x;
    return x;
}

int main(void)
{
    calculate();
    printf("\nResult: %f", x);
    return 0;
}
