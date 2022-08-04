#include <stdio.h>
#include <locale.h>

int main(void)
{
    char name[10];
    char surname[10];
    printf("Input your name:");
    scanf("%s", name);
    printf("\nInput your surname:");
    scanf("%s", surname);
    printf("\nYour name is %s %s", surname, name);
    return 0;
}