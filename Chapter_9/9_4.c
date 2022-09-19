#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

double harmonic_mean(double a, double b)
{
    double harmonic;
    
    harmonic = 2 / ((1 / a) + (1 / b));
    
    return harmonic;
}

int main(void)
{
    double a, b, harmonic;
    
    printf("\nInput first double number: ");
    scanf("%lf", &a);
    printf("\nInput second double number: ");
    scanf("%lf", &b);
    
    harmonic = harmonic_mean(a, b);
    
    printf("\nHarmonic mean is: %lf", harmonic);

    return 0;
}
