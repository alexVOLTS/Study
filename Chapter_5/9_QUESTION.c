#include <stdio.h>
#include <locale.h>
#include <float.h>

double x;
double y;
double temp;
int scanfresult;


int Temperatures()
{
    const double kelvin = 273.16;
    const double f1 = 5.0 / 9.0;
    const double f2 = 32.0;
    double x = f1 * (temp - f2);
    double y = x + kelvin;
    printf ("Numbers %.2lf and %.2lf", x, y);
    return x, y;
}

int Input ()
{
    printf("\nInput fahrenheit temperature: ");
    scanfresult = scanf("%lf", &temp);
    return temp, scanfresult;
}

int main (void)
{
    Input();
    Temperatures();
    while (scanfresult == 1)
    {
        printf("\nTemperature Celsium = %.2lf", x);
        printf("\nTemperature Kelvin = %.2lf", y);
        Input();
    }
    printf("\nEnd of the program");
    return 0;
}