#include <stdio.h>
#include <locale.h>

int main(void)
{
    char name[15];
    char surname[15];
    printf ("Input your name: ");
    scanf("%s", &name);
    printf("\nInput your surname: ");
    scanf("%s", &surname);
    printf("\n%15s %15s", name, surname);
    printf("\n%15d %15d", strlen(name), strlen(surname));
    return 0;
}