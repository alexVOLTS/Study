#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define TWO          2u
#define IS_ODD(x)    (((x) & 1) == 1)

unsigned int x;
unsigned int operation; 


int first(void)
{
    printf("Input int number:\n");
    scanf("%d", &x);
    if (x % TWO == 0)
    {
        printf("\neven");
    }
    else
    {
        printf("\nodd"); 
    }
    return 0;
}

int second(void)
{
    printf("\nInput int number:\n");
    scanf("%d", &x);
    if (IS_ODD(x))
    {
        printf("\nodd");
    }
    else
    {
        printf("\neven");
    }
    return 0;
}

int third(void)
{
    printf("\nInput int number:\n");
    scanf("%d", &x);
    operation = x % TWO;
    bool result = operation == 0;
    if (result)
    {
        printf("\neven");
    }
    else
    {
        printf("\nodd"); 
    }
    return 0;
}

int main(void)
{
    first();
    second();
    third();
}
