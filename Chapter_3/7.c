#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float height;
    printf("Input your height in inches: \t");
    scanf("%f", &height);
    float cm = height * 2.54;
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
    
}