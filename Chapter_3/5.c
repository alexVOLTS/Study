#include <stdio.h>
#include <limits.h>
#include <float.h>

#define SECONDS_IN_YEAR    3.156E7f

int main(void)
{
    int year;

    printf("Input your age in years:\t");
    scanf("%d", &year);

    int sec = year * SECONDS_IN_YEAR;

    printf("\n Your age in seconds: %d seconds", sec);
    return 0;
}