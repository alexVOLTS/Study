#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define FIRST_GUESS    50u

bool first_ask(char answer)
{
    while (getchar() != 'y') {
        printf("Is your number higher than 75?");
    }
}


int main(void)
{
    int guess;
    char answer;
    bool right;
    
    printf("\nChoose integer number from 1 to 100. I will try to guess it");
    scanf("%d", &guess);
    printf("\nPress 'y' if my guess is right");
    printf("\nPress 'n' if my guess is wrong");
    
    
    return 0;
}
