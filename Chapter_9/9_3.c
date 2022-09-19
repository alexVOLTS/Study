#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

void chline (char ch, int i, int j)
{
    printf("\n");
    
    for (int c = 0; c < j; c++) {
        for (int a = 0; a < i; a++) {
            printf(" %c", ch);
        }
            printf("\n");
    }
}

int main(void)
{
    char ch;
    int i, j;
    
    printf("\nInput a symbol ");
    scanf("%c", &ch);
    
    printf("\nInput a number of this symbols: ");
    scanf("%d", &i);
    
    printf("\nInput a number of lines ");
    scanf("%d", &j);
    
    chline(ch, i, j);
    
    return 0;
}
