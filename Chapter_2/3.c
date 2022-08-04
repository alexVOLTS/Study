#include <stdio.h>
#include <locale.h>

int main(void)
{
    int age = 24;
    int age_days = age * 365;
    printf("age = %u \n", age);
    printf("days = %u \n", age_days);
    return 0;
}