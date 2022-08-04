#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    
    char ascii;
    printf("Enter ASCII code:\n");
    scanf("%d", &ascii);

    printf("ASCII code for %d is %c", ascii, ascii);
    getchar();

    return 0;

}