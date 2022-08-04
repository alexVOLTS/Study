#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float quart;
    printf("Input water volume in quarts:\t");
    scanf("%f", &quart);
    float weight = 950;
    float molecul = 3.0E-23;
    float number = (quart * weight) / molecul;
    printf("\n Water molecules number: %f", number);
    return 0;
}