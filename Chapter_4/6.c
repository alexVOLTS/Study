#include <stdio.h>
#include <locale.h>

int main()
{
    char name[15];
    char surname[15];
    printf ("Введите имя: ");
    scanf ("%s", &name);
    printf ("\nВведите фамилию: ");
    scanf ("%s", &surname);
    printf ("\n%15s %15s", name, surname);
    printf ("\n%15d %15d", strlen(name), strlen(surname));
}