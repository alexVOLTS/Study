#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define GRID_ASCII    35u

int main(void)
{
    char character;
    int counter = 0;
    int letter;
    character = getchar();
    
    while(character != GRID_ASCII){
        if(character == 'e'){
            letter = 1;
        }
        else if(character == 'i' && letter == 1){
                counter++;
                letter = 0;
        }
        character = getchar();
    }
    printf("\nCount of ei combinations: %d", counter);
    
    return 0;    
}
