#include <stdio.h>
#include <locale.h>
#include <float.h>

#define X 60;

float mins;

int wtf ()
{
    printf ("\nВведите время в минутах: ");
    scanf ("%f", &mins);
    return mins;
}

int cycle ()
{
    while (mins > 0)
    {
        float time1 = mins/X;
        printf ("\nВремя в часах:%.3f", time1);
        int a = (int) time1;
        float b = time1 - a;
        printf ("\nДробная часть равна %f", b);
        float c = (int) (b * 60);
        printf ("\nПереводим дробную часть в минуты: %.0f", c);
        printf ("\nВремя в часах и минутах: %d часов %.0f минут(ы)", a, c);
        wtf ();
    }
    printf ("\n\tТы ебо-бо что ли?!");
}

int main()
{
    wtf ();
    cycle ();
    printf ("\n\tПопробуешь еще раз, шутник?");
    wtf();
    return 0;
}