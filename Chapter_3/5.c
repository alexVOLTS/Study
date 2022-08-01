#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int year;
    printf ("Введите возраст в годах:\t");
    scanf ("%d", &year);
    int sec = year*3.156E7;
    printf ("\n Возраст в секундaх: %d seconds", sec);
    return 0;
}