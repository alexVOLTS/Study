#include <stdio.h>
#include <locale.h>
#include <float.h>

int main(void)
{
    float mils;
    int gallons;
    printf ("Input the number of traveled miles: gasoline");
    scanf ("%f", &mils);
    printf ("\nInput the number of consumed gallons of oil: ");
    scanf ("%d", &gallons);
    float travel = mils / gallons;
    printf ("\nYou've travelled %.1f miles per one gallon of a gasoline", travel);
    float litre = gallons * 3.785;
    float km = mils * 1.609;
    float rashod = (litre / km) * 100;
    printf ("\nYou've consumed %.1f litres of a gasoline on 100 kilometers", rashod);
    return 0;
}