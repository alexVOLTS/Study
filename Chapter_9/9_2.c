#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

void chline (char ch, int i, int j)
{
    printf("\n");
    
    for (int a = 1; a <= j; a++) {
        printf("\t%d", a);
    }
    
    printf("\n");
    
    for (int a = 1; a <= j; a++) {
        if (a == i) {
            printf("\t%c", ch);
        }
        else if (a == j) {
            printf("\t%c", ch);
        }
        else {
            printf("\t");
        }
    }
}

int main(void)
{
    char ch;
    int i, j;
    
    printf("\nInput a symbol to put it in columns from i to j: ");
    scanf("%c", &ch);
    
    printf("\nInput i column number: ");
    scanf("%d", &i);
    
    printf("\nInput j column number: ");
    scanf("%d", &j);
    
    chline(ch, i, j);
    
    return 0;
}
