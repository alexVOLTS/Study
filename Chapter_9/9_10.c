#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

static void to_base_n(unsigned long n, int x);
static void remainder_of_the_division(int r);

int main(void)
{
    unsigned long number;
    int notation;
    
    printf("\nInput number and its notation (q to exit): ");
    
    while ((scanf("%lu", &number) == 1) && (scanf("%d", &notation) == 1)) {
        printf("\nNew number is: ");
        
        to_base_n(number, notation);
        
        putchar('\n');
        printf("\nInput number and its notation (q to exit): ");
    }
    
    return 0;
}

void to_base_n(unsigned long x, int y)
{
    int result;
    
    result = x % y;
    
    if (x >= y) {
        to_base_n(x / y, y);
    }
    
    remainder_of_the_division(result);
}

void remainder_of_the_division(int r)
{
       switch (r) {
        case 0:
            putchar('0');
            break;
        case 1:
            putchar('1');
            break;
        case 2:
            putchar('2');
            break;
        case 3:
            putchar('3');
            break;
        case 4:
            putchar('4');
            break;
        case 5:
            putchar('5');
            break;
        case 6:
            putchar('6');
            break;
        case 7:
            putchar('7');
            break;
        case 8:
            putchar('8');
            break;
        case 9:
            putchar('9');
            break;
    }
}
