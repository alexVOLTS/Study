#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

#define WEIGHT     950.0f
#define MOLECUL    3.0E-23f

int main(void)
{
    float quart;

    printf("Input water volume in quarts:\t");
    scanf("%f", &quart);

    float number = (quart * WEIGHT) / MOLECUL;

    printf("\n Water molecules number: %f", number);
    return 0;
}