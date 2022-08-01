#include <stdio.h>
#include <locale.h>
#include <float.h>

int main()
{
    int number;
    printf ("Введите ЦЕЛОЕ число: ");
    scanf ("%d", &number);
    
    for (int i = 0; i < 10; i++)
    {
        printf ("\t%d", number);
        number++;
    }
    return 0;
}