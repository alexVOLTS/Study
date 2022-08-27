#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char number [8];
    printf("\n Input eight number:");
    scanf("%s", &number);
    
    for (int i = 0; i <= strlen(number); i++){
        printf("%c", number[strlen(number) - i]);
    }
    return 0;
}