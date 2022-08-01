#include <stdio.h>
#include <locale.h>

int main ()
{
    char name[15];
    printf ("Напишите ваше имя\n");
    scanf ("%s", name);
    printf ("\"%s\"\n", name);
    printf ("\"%20s\"\n", name);
    printf ("\"%-20s\"\n", name);
    printf ("%*s", strlen(name)+3, name);
    return 0;
}