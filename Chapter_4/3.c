#include <stdio.h>

int main()
{
    float num1;
    printf("Enter number:");
    scanf("%f", &num1);
    printf("You entered: %.1f or %.1e\n", num1, num1);
    printf("which is also: %+.3f or %.3E\n", num1, num1);
    return 0;
}