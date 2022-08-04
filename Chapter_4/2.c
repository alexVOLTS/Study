#include <stdio.h>
#include <locale.h>

int main(void)
{
    char name[15];
    printf("Input your name\n");
    scanf("%s", name);
    printf("\"%s\"\n", name);
    printf("\"%20s\"\n", name);
    printf("\"%-20s\"\n", name);
    printf("%*s", strlen(name) + 3, name);
    return 0;
}