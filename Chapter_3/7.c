#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

#define INCH_TO_CM    2.54f

int main(void)
{
    float height;

    printf("Input your height in inches: \t");
    scanf("%f", &height);

    float cm = height * INCH_TO_CM;

    printf("\nYour height in inches: %f", height);
    printf("\nYour height in cantimeters: %f", cm);
    
    if (cm > 180)
    {
        printf("\nOMG You're Michael Jordan monkaOMEGA");
    }
    else
    {
        printf("\nLUL You're Eldar Jarahov KEKW");
    }
    
    return 0;
}