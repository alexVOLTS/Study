#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

int translator(void)
{
    int x[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char y[13][3] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    unsigned int z;
    printf("\nInput number:");
    scanf("%d", &z);
    int number = z;
    if (z < 0 || z > 3999)
    {
        printf("\nNumber must be in a range 0 - 3999");
        return 0;
    }
    for (int i = 0; i < 13; i++)
    {
        while (z >= x[i])
        {
            printf("%s", y[i]);
            z -= x[i];
        }
    }
    if (number == 0)
    {
        printf("\nN");
        return 0;
    }
    return 0;
}

int main(void)
{
    translator();
    return 0;
}