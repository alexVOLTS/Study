#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char symbol;
    int enter_counter = 0;
    int space_counter = 0;
    int symbols_counter = 0;
    
    while((symbol = getchar()) != '#'){
        if(symbol == ' '){
            space_counter++;  
        }
        if(symbol == '\n'){
            enter_counter++;
        }
        symbols_counter++;
    }
    printf("\nNumber of spaces: %d\nNumber of enters: %d\nNumber of symbols: %d", space_counter, enter_counter, symbols_counter);
    
    return 0;
}
