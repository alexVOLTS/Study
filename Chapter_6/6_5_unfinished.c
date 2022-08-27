#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define ROWS 5
#define COLUMNS 5

int main(void)
{
    int  rows, space, down;
    char symbol, letter;
    
    printf("Input any letter: ");
    scanf("%c", &symbol);
    
    for (int i = 0; i < 5; i++){
        for (space = i; space < 4; space++){
            printf(" ");
        }
        for (down = i, letter = symbol; down >= 0; down--){
            printf("%c", letter++);
        }
        printf("\n");
    }
}