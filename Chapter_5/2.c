#include <stdio.h>
#include <locale.h>
#include <float.h>

int main(void)
{
    int number;
    printf("Input INT number: ");
    scanf("%d", &number);
    
    for (int i = 0; i < 10; i++)
    {
        printf("\t%d", number);
        number++;
    }
    return 0;
}