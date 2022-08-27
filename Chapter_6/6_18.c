#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define DANBAR_NUMBER    150u
#define DOUBLE           2u

int main(void)
{
    int i = 0;
    int counter = 1;
    int friends = 5u;
    
    do{
        friends = (friends - counter)*DOUBLE;
        counter++;
        printf("\nNumber of friends at the end of this week: %d", friends);
    } while ((friends < (10 + DANBAR_NUMBER) && (friends < (DANBAR_NUMBER - 10)))); /* Approximation */
    return 0;
}
