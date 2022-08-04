#include <stdio.h>
#include <locale.h>

int jolly(void)
{
    printf("\nHe's funny guy!");
}
int deny(void)
{
    printf("\nNo one can deny this!");
}

int main(void)
{
    jolly();
    jolly();
    jolly();
    deny();
}