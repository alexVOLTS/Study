#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>


int ch(char);

int translator(char a)
{
    int value = 0;
    
    if (a == 'I') return 1;
    if (a == 'V') return 5;
    if (a == 'X') return 10;
    if (a == 'L') return 50;
    if (a == 'C') return 100;
    if (a == 'D') return 500;
    if (a == 'M') return 1000;
    return -1;
}

int converter(char number[])
{
    int result = 0;
    
    for (int i = 0; i < strlen(number); i++)
    {
        int symbol_1 = translator(number[i]);
        
        if (i + 1 < strlen(number))
        {
            int symbol_2 = translator(number[i + 1]);
            
            if (symbol_1 >= symbol_2)
            {
                result = result + symbol_1;
            }
            else
            {
                result = result + symbol_2 - symbol_1;
                i++;
            }
        }
        else
        {
            result = result + 1;
        }
    }
    return result;
}

int main(void)
{
    char number[20];
    printf("\nEnter roman number:");
    scanf("%s", &number);
    printf("Value is: %d", converter(number));
    
    return 0;
}
