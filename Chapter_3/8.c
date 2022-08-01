#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main()
{
    float cup;
    printf ("Введите объем в чашках: \t");
    scanf ("%f", &cup);
    
    float pinta = 2*cup;
    float ounce = cup/8;
    float big_spoon = cup/16;
    float spoon = cup/48;

    printf ("\nОбъем в пинтах: %f", pinta);
    printf ("\nОбъем в унциях: %f", ounce);
    printf ("\nОбъем в столовых ложках: %f", big_spoon);
    printf ("\nОбъем в чайных ложках: %f", spoon);
}