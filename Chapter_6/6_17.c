#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define PERCENT    0.08f
#define TAKE       100000u

int main(void)
{
    int deposit = 1000000.0f;
    int count = 0;

    do {
        deposit += (deposit * PERCENT);
        deposit -= TAKE;
        count++;
    } while (deposit >= 0);
    
    printf("\nYears to have 0 BUCKS: %d", count);
}
