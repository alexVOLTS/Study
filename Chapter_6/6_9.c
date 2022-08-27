#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

float c;
int type_1, type_2;

float input(float a, float b)
{
    c = ((a - b) / (a * b));
    return c; /* Returning c */
}

int main(void)
{
    float a, b;

    printf("\nInput first and second floats: ");

    while(((type_1 = scanf("%f", &a)) == 1) && (type_2 = scanf("%f", &b)) == 1){
        input(a, b);
        printf("\nResult: %f\n", c);
    }

    printf("\nThis is not a float number");
    return 0;
}
