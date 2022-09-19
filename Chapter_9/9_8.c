#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

double power(double *number, int *degree)
{
    double pow_num = 1;
    
    if (*number == 0) {
        pow_num = 0;
    }
    if (*degree == 0) {
        pow_num = 1;
    }
    if ((*number == 0) && (*degree == 0)) {
        printf("\nAre u insane?");
    }
    
    for (int i = 0; i < (abs(*degree)); i++) {
        pow_num *= *number;
    }
    
    if (*degree < 0) {
        pow_num = 1 / pow_num;
    }
    
    return pow_num;
}

int main(void)
{
    double number, power_number;
    int degree;
    
    printf("\nInput any letter or symbol that is not a number to QUIT from the program");
    printf("\n\nInput a number ");
    printf("and a degree to power this number: ");
    
    while (scanf("%lf%d", &number, &degree) == 2) {
        power_number = power(&number, &degree);
        
        printf("\nResult: %.5lf", power_number);
        printf("\n");
    }
	
	printf("\nEnd of the program...");
    
    return 0;
}
