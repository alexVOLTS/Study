#include <stdio.h>
#include <locale.h>
#include <float.h>

double x;
double y;
double temp;
int scanfresult;
const double kelvin = 273.16;
const double f1 = 5.0 / 9.0;
const double f2 = 32.0;


int Temperatures(void)
{
    double x = f1 * (temp - f2);
    double y = x + kelvin;
    printf("\nTemperature Celsium = %.2lf", x);
    printf("\nTemperature Kelvin = %.2lf", y);
}

int Input(void)
{
    printf("\nInput fahrenheit temperature: ");
    scanfresult = scanf("%lf", &temp);
    return scanfresult;
}

int main(void)
{
    Input();
    while (scanfresult == 1)
    {
        Temperatures();
        Input();
    }
    printf("\nEnd of the program");
    return 0;
}