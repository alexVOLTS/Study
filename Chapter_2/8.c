#include <stdio.h>
#include <locale.h>

int two ()
{
    printf ("\n two");
}

int one_three ()
{
    printf ("\n one");
    two ();
    printf ("\n three");
}

int main ()
{
    printf ("Начинаем:");
    one_three();
    printf ("\n порядок!");
}
