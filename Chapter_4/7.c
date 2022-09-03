#include <stdio.h>
#include <locale.h>
#include <float.h>

int main(void)
{
    double a = 1.0 / 3.0;
    float b = 1.0 / 3.0;

    printf("\n%.4f\t%.4f", a, b);
    printf("\n%.12f\t%.12f", a, b);
    printf("\n%.16f\t%.16f", a, b);
    printf("\n%d\t%d", FLT_DIG, DBL_DIG);

    return 0;
}