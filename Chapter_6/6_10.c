#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

int a, b;
int c = 0;

void input()
{
    printf("\nInput low number: ");
    scanf("%d", &a);
	
    printf("\nInput high number: ");
    scanf("%d", &b);
}

int main(void)
{
    input();
    int d = a;
    
    while (a < b) {
        for (a; a <= b; a++){
            c = c + (a * a);
        }
        printf("\nSum of squares of int numbers from %d to %d is %d ", d, b, c);
        c = 0;
        input();
    }
	
    printf("\n\tEnd of the program...");
	
    return 0;
}
