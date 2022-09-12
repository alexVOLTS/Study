#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    int counter;
    
    while ((ch = getchar()) != EOF) {
        counter++;
    }
    
    printf("\nNumber of symbols: %d", counter);
    
    return 0;
}
