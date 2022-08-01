#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    float growth;
    printf ("Введите рост в дюймах: \t");
    scanf ("%f", &growth);
    float cm = growth*2.54;
    printf ("\nВаш рост В дюймаx: %f",growth);
    printf ("\nВаш рост В сантиметрах: %f", cm);
    
        if (cm > 180)
        {
            printf ("\nЕбать ты Майл Джордан monkaOMEGA");
        }
        else
        {
            printf ("\nЕбать ты ЭЛЬДАР ДЖАРАХОВ KEKW");
        }
    
}