#include <stdio.h>
#include <locale.h>
#include <float.h>

#define foot 0.0328084;
#define inch 0.393701;

float cm;

int input()
{
    printf("\nInput height in centimeters:\t");
    scanf("%f", &cm); 
    return cm;
}

int cycle(void)
{
    while (cm > 0)
    {
        float x = cm * foot;
        float y = cm * inch;
        printf("\n%.1f centimeters = %.0f foots, %.1f inches (<=0 to exit from the program)", cm, x, y);
        input ();
    }
    printf ("Program ends now.");
}

int main(void)
{
    input();
    cycle();
    return 0;
}