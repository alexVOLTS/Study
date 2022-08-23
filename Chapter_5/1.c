#include <stdio.h>
#include <locale.h>
#include <float.h>

#define MINS_IN_HOUR    60;

float mins;

int wtf()
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
        float c = (int) (b * 60);
        printf("\nTime in hourse and minutes: %d hours %.0f minutes", a, c);
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
