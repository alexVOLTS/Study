#include <stdio.h>
#include <string.h>

int main(void)
{
    unsigned int number, revers = 0;

    printf("\nInput integer number: ");
    scanf("%d", &number);

    while (number != 0)
    {
        revers = revers * 10 + number % 10;
        number = number / 10;
    }
    printf("\nReversed number is: %d", revers);
    return 0;
}
