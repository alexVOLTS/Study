#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

void larger_of(double *x, double *y, double *z)
{
    if (*z < *x) {
        swap(z, x);
    }
    if (*y < *x) {
        swap(y, x);
    }
    if (*z < *y) {
        swap(z, y);
    }
}

void swap(double *a, double *b)
{
    double swap = *a;
    *a = *b;
    *b = swap;
}

int main(void)
{
    double x, y, z;
    
    printf("\nInput X double number: ");
    scanf("%lf", &x);
    printf("\nInput Y double number: ");
    scanf("%lf", &y);
    printf("\nInput Z double number: ");
    scanf("%lf", &z);
    
    larger_of(&x, &y, &z);
    
    printf("\nNew X Y Z are: %.3lf  %.3lf  %.3lf", x, y, z);

    return 0;
}
