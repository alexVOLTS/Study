#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define __SIZE    8

int i = 0;
int counter = 1;

int main(void)
{
    int a[__SIZE];
    int b = 1;
    
    for (i; i < __SIZE; i++){
        b = 2 * b;
        a[i] = b;
        // counter++;
        do {
            printf("\nPowers of two: TWO[%d] = %d", i, a[i]); /* Powers of two - обозначение степеней двойки */
            counter++;
        }
        while (counter < __SIZE);
    }
    
    printf("\nProgram ends here...");
    return 0;
}
