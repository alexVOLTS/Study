#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float cup;
    printf("Input volume in cups: \t");
    scanf("%f", &cup);
    
    float pint = 2 * cup;
    float ounce = cup / 8;
    float big_spoon = cup / 16;
    float spoon = cup / 48;

    printf("\nVolume in pints: %f", pint);
    printf("\nVolume in ounces: %f", ounce);
    printf("\nVolume in spoons: %f", big_spoon);
    printf("\nVolume in tea spoons: %f", spoon);
}