#include <stdio.h>

int main(void)
{
    float rost;
    char name[15];
    printf("Input your height in inches: ");
    scanf("%f", &rost);
    printf("\nInput your name: ");
    scanf("%s", &name);
    float foot = rost / 12;
    printf("\n%s your height is %.2f inches", name, foot);
    return 0;
}