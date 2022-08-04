#include <stdio.h>
#include <locale.h>

int smile ()
{
    char smile[] = "Smile!";
    printf ("%s", smile);
}

int main (void)
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
}