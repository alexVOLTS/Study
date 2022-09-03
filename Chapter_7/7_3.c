#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define ZERO_ASCII        48u
#define IS_ODD(number)    (((number) & 1) == 1)
#define IS_EVEN(number)   (((number) & 1) == 0)

int main(void)
{
    int number;
    float average, flt_odd, flt_counter;
    int odd_number = 0;
    int even_counter = 0;
    int symbols_counter = 0;
    int odd_counter = 0;
    
    while((number = (getchar()-ZERO_ASCII)) != 0){ /* getchar(0) = 48. That's why I need to minus this */
        if (IS_ODD(number)){
            odd_number += number;
            odd_counter++;
        }
        if (IS_EVEN(number)){
            even_counter++;
        }
        symbols_counter++;
    }
    
    flt_odd = (float)odd_number;
    flt_counter = (float)odd_counter;
    average = flt_odd / flt_counter;
    
    printf("\nYou have inputted: %d numbers", symbols_counter);
    printf("\nThere are %d even numbers among them", even_counter);
    printf("\nAverage number of the odd numbers is: %f", average);
    
    return 0;
}
