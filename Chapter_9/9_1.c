#include <stdio.h>
#include <stdbool.h>

double min (double x, double y)
{
    double minimal;
    
    if (x < y) {
        minimal = x;
    }
    else {
        minimal = y;
    }
    
    return minimal;
}



int main(void)
{
    double x, y, z;
    
    printf("\nInput first double number: ");
    scanf("%lf", &x);
	
    printf("\nInput second double number: ");
    scanf("%lf", &y);
    
    z = min(x, y);
    
    printf("\nMininal number is %lf", z);
    
    return 0;
}
