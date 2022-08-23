#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

#define SECONDS    3.156E7f

int main(void)
{
    int year;

    printf("Input your age in years:\t");
    scanf("%d", &year);

    int sec = year * SECONDS;

    printf("\n Your age in seconds: %d seconds", sec);
    return 0;
}