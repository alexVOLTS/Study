#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

int main(void)
{
    int a, z;
    
    printf("\nInput low boundary of the table: ");
    scanf("%d", &a);
    printf("\nInput high boundary of the table: ");
    scanf("%d", &z);
    
    for(a; a <= z; a++){
        int b = a * a;
        int c = a * a * a;
        printf("\n%d\t%d\t%d", a, b, c);
    }
    printf("\n");
    return 0;
}
