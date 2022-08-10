#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define y 2u

unsigned int x;
unsigned int operation; 


int first(void)
{
    printf("Input int number:\n");
    scanf("%d", &x);
    if (x % y == 0)
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
    if (x & 1) // I've used logical operation AND to check last bit of number x and number 2. Even numbers have 0 in their first bit
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
    operation = x % y;
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
    return 0;
}
