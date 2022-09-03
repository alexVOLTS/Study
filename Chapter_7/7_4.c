#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define GRID_ASCII            35u
#define EXCLAMATION_POINT     33u
#define DOT                   46u
#define DOT_TO_EXCLM_POINT    13u   

int main(void)
{
    char character;
    int replacement = 0;
    character = getchar();
    
    while(character != GRID_ASCII){
        if(character == DOT){
            putchar(character - DOT_TO_EXCLM_POINT);
            replacement++;
        }
        else if (character == EXCLAMATION_POINT){
            putchar(character);putchar(character);
            replacement++;
        }
        else{
            putchar(character);
        }
        character = getchar();
    }
    printf("\nNumber of replacements: %d", replacement);
    
    return 0;
}
