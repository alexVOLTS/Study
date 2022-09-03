#include <stdio.h>
#include <locale.h>
#include <float.h>

#define MINS_IN_HOUR    60u;

float mins;

int wtf(void)
{
    printf("\nInput time in minutes:");
    scanf("%f", &mins);
    return mins;
}

int cycle(void)
{
    while (mins > 0)
    {
        float time1 = mins / MINS_IN_HOUR;
        printf("\nTime in hours is %.3f", time1);

        int a = (int) time1;
        float b = time1 - a;
        float c = (int) (b * MINS_IN_HOUR);

        printf("\nTime in hourses and minutes: %d hours %.0f minutes", a, c);
        wtf ();
    }
    printf("\n\tDAFAQ?? Are you braindead?!");
}

int main(void)
{
    wtf();
    cycle();
    printf("\n\tWould you like to try again clown?");
    wtf();
    return 0;
}
