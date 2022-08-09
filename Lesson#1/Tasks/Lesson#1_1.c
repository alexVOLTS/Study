#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define y 2u

unsigned int x;
unsigned int operation; 


int first()
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

int second()
{
    printf("\nInput int number:\n");
    scanf("%d", &x);
    if (x & 2) // I've used logical operation AND to check last bit of number x and number 2. Even numbers have 0 in their first bit
    {
        printf("\neven");
    }
    else
    {
        printf("\nodd"); 
    }
    return 0;
}

int third()
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
