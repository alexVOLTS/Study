#include <stdio.h>

#define INCHES_IN_FOOT    12.0f

int main(void)
{
    float height;
    char name[15];

    printf("\nInput your height in inches: ");
    scanf("%f", &height);
    printf("\nInput your name: ");
    scanf("%s", &name);

    float foot = height / FOOT;

    printf("\n%s your height is %.2f inches", name, foot);
    return 0;
}
