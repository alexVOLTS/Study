#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>


#define     __TWO_THOUSAND          63113904000u    // Seconds in 2000 years
#define     __HOUR_TO_SEC           3600u           // Hour to seconds
#define     __MINUTE_TO_SEC         60u             // Minute to seconds
#define     __DAY_TO_SEC            86400u          // Day to seconds
#define     __YEAR_TO_SEC           31536000u       // Normal year to seconds
#define     __YEAR_TO_SEC_LEAP      31622400u       // Leap year to seconds
#define     __MONTH_TO_SEC          2678400u        // 31 days month to seconds
#define     __DAYS_THIRTY           2592000u        // 30 days month to seconds
#define     __DAYS_FEBRUARY         2419200u        // Normal february days quantity to seconds 
#define     __DAYS_FEBRUARY_LEAP    2505600u        // Leap year february days quantity to seconds

int calculator(void)
{
    unsigned int hour, minute, second, day, month, year;
    printf("\nInput date (HH:MM:SS DD.MM.YYYY): ");
    scanf("%d %d %d %d %d %d", &hour, &minute, &second, &day, &month, &year);
    
    
    // if ((hour > 24)) or (hour < 0))
    // {
    //     printf ("\nWrong number of hours!");
    //     return 0;
    // }
    
    // if ((minute > 60)) or (minute < 0))
    // {
    //     printf ("\nWrong number of minutes!");
    //     return 0;
    // }
    
    // if ((second > 60)) or (second < 0))
    // {
    //     printf ("\nWrong number of seconds!");
    //     return 0;
    // }
    
    int result;
    long long int date;
    long long int time;
    int i = 0;
    unsigned long long int sec_year = 0;
    unsigned long long int sec_month = 0;
    unsigned long long int sec_day = 0;
    bool leap;
    
    for (i = 0; i < year; i++)
    {
        if ((year - i) % 4 == 0)
        {
            if ((year - i) % 100 == 0)
            {
                if ((year - i) % 400 == 0)
                {
                    //printf ("\nLeap year!");
                    sec_year = sec_year + __YEAR_TO_SEC_LEAP;
                }
                else
                {
                    sec_year = sec_year + __YEAR_TO_SEC;
                }
            }
            else
            {
                sec_year = sec_year + __YEAR_TO_SEC;
            }
        }
        else
        {
            sec_year = sec_year + __YEAR_TO_SEC;
        }
    }
    
    if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    leap = true;
                }
                else
                {
                    leap = false;
                }
            }
            else
            {
                leap = false;
            }
        }
    else
    {
        leap = false;    
    }
    
    for (i = 0; i < month; i++)
    {
        if (month <= 12)
        {
            if ((month - i) == (4 || 6 || 9 || 11))
            {
                sec_month = sec_month + __DAYS_THIRTY;
            }
            else if ((month - i) == 2)
            {
                if (leap = true)
                {
                    sec_month = sec_month + __DAYS_FEBRUARY_LEAP;
                }
                else
                {
                    sec_month = sec_month + __DAYS_FEBRUARY;
                }
            }
            else
            {
                sec_month = sec_month + __MONTH_TO_SEC;
            }
        }
        else
        {
            printf("Too many months!");
            return 0;
        }
    }
    
    for (i = 0; i < day; i++)
    {
        if (day < 31)
        {
            sec_day = sec_day + __DAY_TO_SEC;  
        }
        else 
        {
            printf("\nToo many days!");
            return 0;
        }
    }
    
    date = sec_year + sec_month + sec_day;
    time = (hour * __HOUR_TO_SEC) + (minute * __MINUTE_TO_SEC) + second + date;
    result = time - __TWO_THOUSAND;
    printf ("\nTime in seconds: %d", abs(result));
}


int main(void)
{
    calculator();
    return 0;
}
