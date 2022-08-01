#include <stdio.h>
#include <locale.h>

int smile ()
{
    char smile[] = "Улыбайся!";
    printf ("%s", smile);
}

int main ()
{
    smile();
    smile();
    smile();
    printf ("\n");
    smile();
    smile();
    printf ("\n");
    smile();
}