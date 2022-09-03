#include <stdio.h>
#include <locale.h>
#include <float.h>

#define GALLON_TO_LITERS    3.785f
#define MILL_TO_KM    1.609f
#define HUNDRED_KM    100.0f

int main(void)
{
    float mils;
    int gallons;

    printf ("\nInput the number of traveled miles: gasoline");
    scanf ("%f", &mils);
    printf ("\nInput the number of consumed gallons of oil: ");
    scanf ("%d", &gallons);

    float travel = mils / gallons;
    printf ("\nYou've travelled %.1f miles per one gallon of a gasoline", travel);

    float litre = gallons * GALLON_TO_LITERS;
    float km = mils * MILL_TO_KM;
    float rashod = (litre / km) * HUNDRED_KM;

    printf ("\nYou've consumed %.1f litres of a gasoline on %.1f kilometers", rashod, HUNDRED_KM);
    return 0;
}