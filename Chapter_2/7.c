#include <stdio.h>
#include <locale.h>

void smile(void)
{
    char smile[] = "Smile!";
    printf ("%s", smile);
}

int main(void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    return 0;
}
