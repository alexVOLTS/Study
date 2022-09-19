#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

void larger_of(double *x, double *y)
{
    if ((*x - *y < FLT_EPSILON) && (*y - *x < FLT_EPSILON)) {
        printf("\nYou've inputted equal numbers!");
    }
    else if (*x > *y) {
        *y = *x;
    }
    else {
        *x = *y;
    }
}

int main(void)
{
    double x, y;
    
    printf("\nInput first double number: ");
    scanf("%lf", &x);
    printf("\nInput second double number: ");
    scanf("%lf", &y);
    
    larger_of(&x, &y);
    
    printf("\nNew X and Y are: %.3lf and %.3lf", x, y);

    return 0;
}
