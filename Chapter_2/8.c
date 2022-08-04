#include <stdio.h>
#include <locale.h>

int two (void)
{
    printf("\n two");
}

int one_three (void)
{
    printf("\n one");
    two ();
    printf("\n three");
}

int main (void)
{
    printf("Begin:");
    one_three();
    printf("\n done!");
}
