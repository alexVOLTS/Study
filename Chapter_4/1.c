#include <stdio.h>
#include <locale.h>

int main ()
{
    char name[10];
    char surname[10];
    printf ("Напишите ваше имя:");
    scanf ("%s", name);
    printf ("\nНапишите вашу фамилию:");
    scanf ("%s", surname);
    printf ("\nВаше имя: %s %s", surname, name);
}