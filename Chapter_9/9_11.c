#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

int main(void)
{
    unsigned int fibonacci = 0;
    unsigned int next_fib = 1;
    int number_quantity;
    
    printf("\nInput quantity of Fibonacci numbers: ");
    
    while (scanf("%d", &number_quantity) == 1) {
        for (int i = 0; i < number_quantity; i++) {
            
            fibonacci += next_fib;
            next_fib = fibonacci - next_fib;
            
            printf("\nFibonacci row: %d", fibonacci);
        }
        printf("\n");
    }
    
    return 0;
}
