#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define __SIZE    8

int main(void)
{
    double first[__SIZE];
    double second[__SIZE];
    double calculation = 0.00;
    
    for(int x = 0; x < __SIZE; x++){
        printf("\nInput [%d] element of the first array: ", x);
        scanf("%lf", &first[x]);
    }
    for(int y = 0; y < __SIZE; y++){
        printf("%lf   ", first[y]);
    }
        printf("\n");
    for (int i = 0; i < __SIZE; i++){
        calculation = calculation + first[i];
        second[i] = calculation;
        printf("%lf   ", second[i]);
    }
    
    printf("\n");
    printf("\n\t\t\t\tProgram ends here...");
    return 0;
}
