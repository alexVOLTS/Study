#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define '#'     35u
#define '!'     33u
#define '.'     46u
#define '.!'    13u   

int main(void)
{
    char character;
    int replacement = 0;
    character = getchar();
    
    while(character != '#') {
        if(character == '.') {
            putchar(character - '.!');
            replacement++;
        }
        else if (character == '!') {
            putchar(character);putchar(character);
            replacement++;
        }
        else {
            putchar(character);
        }
        character = getchar();
    }
    printf("\nNumber of replacements: %d", replacement);
    
    return 0;
}
