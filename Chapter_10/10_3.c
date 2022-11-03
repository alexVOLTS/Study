#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define ARRAY_SIZE           5u
#define SWAP(x,y,i)          (x[i]) > (y) ? ((y) = (x[i])) : (0)

static int max_num(int array[]);

int main(void)
{
    int array[ARRAY_SIZE] = {3, 200000000, 1000, 1, 4};
    int result;

    result = max_num(array);
    
    printf("\n\n%d", result);
    
    return 0;
    
}

int max_num(int array[])
{
    int num = 0;
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        SWAP(array, num, i);
    }
    
    return num;
}
