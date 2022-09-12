#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define A    65u
#define Z    90u
#define a    97u
#define z    122u

/* I'm not sure have I done everything that task asked me to do. It's not clear task for me */

int main(void)
{
    int ch;
    int lowercase = 0;
    int cursive = 0;
    int counter = 0;
    
    while ((ch = getchar()) != EOF) {
        if ((ch >= 65) && (ch <= 90)) {
            cursive++; 
        }
        else if ((ch >= 97) && (ch <= 122)) {
            lowercase++;
        }
        else {
            counter++;
        }
    }
    
    printf("\nYou've inputted %d lowercase letters", lowercase);
    printf("\nYou've inputted %d cursive letters", cursive);
    printf("\nYou've inputted %d other symbols", counter);
    
    return 0;
}
