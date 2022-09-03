#include <stdio.h>
#include <locale.h>
#include <float.h>

#define CM_IN_FOOT     0.0328084f
#define CM_IN_INCH     0.393701f

float cm;

int input(void)
{
    printf("\nInput height in centimeters:\t");
    scanf("%f", &cm); 
    return cm;
}

int cycle(void)
{
    while (cm > 0)
    {
        float x = cm * CM_IN_FOOT;
        float y = cm * CM_IN_INCH;

        printf("\n%.1f centimeters = %.0f foots, %.1f inches (<=0 to exit from the program)", cm, x, y);
        input();
    }
    printf ("Program ends now.");
}

int main(void)
{
    input();
    cycle();
    return 0;
}