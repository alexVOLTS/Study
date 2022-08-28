#include <stdio.h>
#include <float.h>
#include <stdbool.h>

#define TWO          2u
#define IS_ODD(x)    (((x) & 1) == 1)

unsigned int x;
unsigned int operation; 

int input(void)
{
    printf("\nInput int number:\n");
    scanf("%d", &x);
}

int first(void)
{
    input();
    if (x % TWO == 0)
    {
        printf("\neven");
    }
    else
    {
        printf("\nodd"); 
    }
}

int second(void)
{
    input();
    if (IS_ODD(x))
    {
        printf("\nodd");
    }
    else
    {
        printf("\neven");
    }
}

int third(void)
{
    input();
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
}

int main(void)
{
    first();
    second();
    third();
    return 0;
}
