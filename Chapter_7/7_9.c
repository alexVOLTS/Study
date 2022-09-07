#include <stdio.h>
#include <stdbool.h>

#define SIZE_OF_ARRAY    25u

int main(void)
{
    int number;
    int prime_number[SIZE_OF_ARRAY] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, \
    43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    
    printf("\nInput positive integer number: ");
    scanf("%d", &number);
    
    for(int i = 0; i < SIZE_OF_ARRAY; i++){
        if(number >= prime_number[i]){
            printf("%d  ", prime_number[i]);
        }
    }
    
    return 0;
}
