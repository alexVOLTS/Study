#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    int year;
    printf("Input your age in years:\t");
    scanf("%d", &year);
    int sec = year * 3.156E7;
    printf("\n Your age in seconds: %d seconds", sec);
    return 0;
}