#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define A        65u
#define Z        90u
#define a        97u
#define z        122u
#define SPACE    32u

int main(void)
{
    int ch;
    int space = 0;
    int counter = 0;
    int calculation[100];
    int average = 0;
    float sum;
    
    while ((ch = getchar()) != EOF) {
        if (((ch >= A) && (ch <= Z)) || ((ch >= a) && (ch <= z))) {
            counter++;
        }
        else if (ch = SPACE) {
            space++;
            calculation[space] = counter;
            average += calculation[space];
            counter = 0;
        }
    }
    
    sum = (float)average / (float)space;
    
    printf("\nMedium number of letters in words: %.2f", sum);
    
    return 0;
}
