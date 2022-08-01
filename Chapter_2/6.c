#include <stdio.h>
#include <locale.h>

int main ()
{
    int toes = 10;
    int a = toes*2;
    int b = toes*toes;
    printf ("toes = %u \n", toes);
    printf ("2 toes = %u \n", a);
    printf ("double toes = %u \n", b);
    return 0;
}