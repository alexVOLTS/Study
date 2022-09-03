#include <stdio.h>
#include <locale.h>
#include <float.h>


int main(void)
{ 
    int count, sum, num;
    count = 0; 
    sum = 0; 

    printf("\nInput number:", num);
    scanf("%d", &num);

    while (count++ < num)
    {
        sum += count; 
        printf("sum = %d\n", sum); 
    }
    return 0;
}
