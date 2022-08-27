#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define __ONE    1.0

int a;
float b, c;

int input()
{
    printf("\nInput number of summaries: ");
    scanf("%d", &a);
    return a;
}

int main(void)
{
    input();
    while (a > 0) {
        for (int i = __ONE; i < (a + __ONE); i++){
            b = b + (__ONE / i);
            c = c - (__ONE / i); 
            }
        printf("\nSubtotal is: %f", b);
        printf("\nSubtotal is: %f", c);
        b = 0;
        c = 0;
        input();
        // printf("\nTotal sum is: %f", b);
        // printf("\nTotal sum is: %f", c);
        }
    printf("\nProgram stops here...");
    return 0;
}
