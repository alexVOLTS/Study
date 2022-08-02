#include <stdio.h>
#include <locale.h>
#include <float.h>


const int week = 7;
float days;

int input ()
{
    printf("\nInput number of days\t");
    scanf("%f", &days);
}

int cycle ()
{
    while (days > 0)
    {
        float quantity = days / week;
        float x = (int) quantity;
        float y = quantity - x;
        float numb = y * week;
        printf("\n%.0f days is %.0f weeks and %.0f days", days, x, numb);
        input();
    }
}

int main(void)
{
    input();
    cycle();
    printf ("\n\t\t\t\tI've seen some cringe");
    printf ("\n\t\t\t\tTry again...");
    input();
    printf ("\n\t\t\t\tYou've killed this program. Deactivation...");
    return 0;
}