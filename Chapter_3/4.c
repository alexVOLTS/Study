#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float num;
    printf("Input number with floating point:\t");
    scanf("%f", &num);
    printf("\n Number with floating point %f", num);
    printf("\n Exponential form of number: %e", num);
    printf("\n Binary exponential notation: %a", num);
}