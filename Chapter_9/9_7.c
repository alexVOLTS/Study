#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define A                     65u
#define Z                     90u
#define a                     97u
#define z                     122u
#define ALPHABET_CALC_HIGH    64u
#define ALPHABET_CALC_LOW     96u

int main(void)
{
    int ch;
    
    while ((ch = getchar()) != EOF) {
        if (((ch >= A) && (ch <= Z))) {
            printf("\nLetter!  %d", (ch - ALPHABET_CALC_HIGH));
        }
        else if (((ch >= a) && (ch <= z))) {
            printf("\nLetter!  %d", (ch - ALPHABET_CALC_LOW));
        }
        else {
            printf("\n-1");
        }
    }
    
    return 0;
}
