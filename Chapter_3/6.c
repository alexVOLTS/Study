#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float kvarta;
    printf ("Введите объем воды в квартах:\t");
    scanf ("%f", &kvarta);
    float weight = 950;
    float molecul = 3.0E-23;
    float number = (kvarta*weight)/molecul;
    printf ("\n Количество молекул воды: %f", number);
    return 0;
}