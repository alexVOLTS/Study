#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define ROWS 6

int main(void)
{
    char letter = 'A';
    
    for (int i = 0; i < ROWS; i++){
        for (int k = 0; k <= i; k++){
            printf("%c", letter++);
        }
        printf("\n");
    }
    return 0;
}
