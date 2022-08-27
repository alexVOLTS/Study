#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

float a, b, c;
int type_1, type_2;

int input(void)
{
    printf("\nInput two floats: ");
    type_1 = scanf("%f", &a);
    type_2 = scanf("%f", &b);
    c = ((a - b) / (a * b));
}

int main(void)
{
    input();
    
    while((type_1) && (type_2)){
        printf("\nResult: %f", c);
        input();
            if((!type_1) && (!type_2)){
            printf("\nThis is not a float number");
            return 0;
        }
    }
    return 0;
}