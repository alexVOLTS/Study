#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float num;
    printf ("Введите значение с плавающей запятой:\t");
    scanf ("%f", &num);
    printf ("\n Запись с фиксирoванной запятой %f", num);
    printf ("\n Экспоненциальная форма записu: %e", num);
    printf ("\n Двоично-экспоненциальное представление: %a", num);
}