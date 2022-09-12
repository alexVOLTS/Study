#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define '#'     35u
#define '!'     33u
#define '.'     46u

int main(void)
{
    char character;
    int replacement = 0;
    character = getchar();
    
    while(character != '#') {
        switch(character) {
            case '.':
                putchar(character - '.!');
                replacement++;
                break;
            case '!':
                putchar(character);putchar(character);
                replacement++;
                break;
            default: 
                putchar(character);
        }
        character = getchar();
    }    
    printf("\nNumber of replacements: %d", replacement);
    
    return 0;    
}
