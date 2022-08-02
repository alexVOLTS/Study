#include <stdio.h>
#include <locale.h>
#include <float.h>

int x;
int y;

int second()
{
    printf("\nInput integer number which will be a second operand: ");
    scanf("%d", &x);
    return x;
}

int first ()
{
    printf("\nInput first operand (<=0 to exit from program): ");
    scanf("%d", &y);
    return y;
}

int cycle ()
{
    while (y > 0)
    {
        int z = y % x;
        printf("\n%d on %d equals %d", y, x, z);
        first();
    }
    printf("\nDone");
}

int main (void)
{
    second();
    first();
    cycle();
    return 0;
}