#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

double power(double number, int degree, double recursion)
{
    double pow_num = 1;
    
    if (number == 0) {
        return 0;
    }
    if (degree == 0) {
        return 1;
    }
    if ((number == 0) && (degree == 0)) {
        printf("\nAre u insane?");
    }
    
    if (degree > 1) {
        return power((number * recursion), (degree - 1), recursion);
    }
    if (degree < -1) {
        return power((number * recursion), (degree + 1), recursion);
    }
}

int main(void)
{
    double number, power_number, recursion;
    int degree;
    
    printf("\nInput any letter or symbol that is not a number to QUIT from the program");
    printf("\n\nInput a number ");
    printf("and a degree to power this number: ");
    
    while (scanf("%lf%d", &number, &degree) == 2) {
        recursion = number;
        power_number = power(number, degree, recursion);
        
        if (degree < 0) {
            printf("\nResult: %.5lf", 1 / power_number);
        }
        else {
            printf("\nResult: %.5lf", power_number);
        }
        
        printf("\n");
    }
	
	printf("\nEnd of the program...");
    
    return 0;
}
