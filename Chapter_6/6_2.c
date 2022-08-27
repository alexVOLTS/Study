#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define    ROWS    5

int main(void)
{
    for (int i = 0; i < ROWS; i++){
        for (int k = i; k >= 0; k--){
            printf("$");
        }
        printf("\n");
    }
    return 0;
}
