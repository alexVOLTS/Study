#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_OF_STRING    8u
#define '#'               35u

int main(void)
{
    char symbol;
    int new_string;
    int symbols_counter = 0;
    
    while((symbol = getchar()) != '#') {
        
        symbols_counter++;
        new_string = (symbols_counter % SIZE_OF_STRING);
        printf("%c ", symbol);
        printf("%d ", symbol);
          
        if (new_string == 0) {
            printf("\n");
        }
    }

    return 0;
}
