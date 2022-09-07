#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define SIZE    256u

int main(void)
{
    char str[SIZE] = "";
    
    printf("\nInput string: ");
    scanf("%255s", &str);
    
    printf("\nReversed string: ");
	
    for (int i = 0; i <= SIZE; i++) {
        printf("%c", str[(SIZE - 1) - i]);
    }
    
    return 0;
}
