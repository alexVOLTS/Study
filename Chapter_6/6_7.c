#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>



int main(void)
{
    char word[100];
    
    printf("\nInput a word: ");
    scanf("%s", &word);
    
    int leght = strlen(word);
    printf("\nWord lenght is %d letters\n", leght);
    
    for (int i = 0; i <= strlen(word); i++){
        printf("%c", word[strlen(word) - i]);
    }
    return 0;
}
