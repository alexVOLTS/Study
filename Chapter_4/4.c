#include <stdio.h>

int main()
{
    float rost;
    char name[15];
    printf ("Напишите рост в дюймах: ");
    scanf ("%f", &rost);
    printf ("\nНапишите имя: ");
    scanf ("%s", &name);
    float foot = rost/12;
    printf ("\n%s ваш рост составляет %.2f футов", name, foot);
}