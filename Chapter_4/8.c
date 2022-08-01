#include <stdio.h>
#include <locale.h>
#include <float.h>

int main()
{
    float mils;
    int gallons;
    printf ("Введите количество пройденных миль: ");
    scanf ("%f", &mils);
    printf ("\nВведите количество израсходованных галлонов бензина: ");
    scanf ("%d", &gallons);
    float travel = mils/gallons;
    printf ("\nВы прошли %.1f миль на одном галлоне бензина", travel);
    float litre = gallons*3.785;
    float km = mils*1.609;
    float rashod = (litre/km)*100;
    printf ("\nВы израсходовали %.1f литров бензина на 100 километров", rashod);
}