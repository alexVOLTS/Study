#include <stdio.h>
#include <locale.h>
#include <stdint.h>
#include <float.h>
#include <stdbool.h>

#define     HOUR_TO_SEC           3600u           // Hour to seconds
#define     MINUTE_TO_SEC         60u             // Minute to seconds
#define     DAY_TO_SEC            86400u          // Day to seconds
#define     YEAR_TO_SEC           31536000u       // Normal year to seconds
#define     YEAR_TO_SEC_LEAP      31622400u       // Leap year to seconds
#define     MONTH_TO_SEC          2678400u        // 31 days month to seconds
#define     DAYS_THIRTY           2592000u        // 30 days month to seconds
#define     DAYS_FEBRUARY         2419200u        // Normal february days quantity to seconds 
#define     DAYS_FEBRUARY_LEAP    2505600u        // Leap year february days quantity to seconds
#define     DEFAULT_YEAR          2000u
#define     DAYS_IN_MONTH         31u
#define     MONTHES_IN_YEAR       12u
#define     FEBRUARY              2
#define     APRIL                 4
#define     JUNE                  6
#define     SEPTEMBER             9
#define     NOVEMBER              11
#define     UNIX_TIME_OFFSET      946684800
    
void calculate_year(int year, int *sec_year)
{
    for (int year_progression = DEFAULT_YEAR; year_progression < year; year_progression++) {
        
        if ((year_progression % 4) == 0) {
            (*sec_year) += YEAR_TO_SEC_LEAP;
        }
        else if (((year_progression % 100) == 0) && ((year_progression % 400) == 0)) {
            (*sec_year) += YEAR_TO_SEC_LEAP;        
        }
        else {
            (*sec_year) += YEAR_TO_SEC;
        }
    }
}

bool is_year_leap(int year)
{
    if (year % 4 == 0) {
        return true;
    }
    else if ((year % 100 == 0) && (year % 400 == 0)){
        return true;
    }
    else {
        return false;
    }
}
    
void calculate_month(int month, int *sec_month, bool leap)
{
    for (int i = 1; i < month; i++) {
        if (((month - i) == APRIL) || ((month - i) ==  JUNE) || ((month - i) ==  SEPTEMBER) || ((month - i) ==  NOVEMBER)) {
            *sec_month += DAYS_THIRTY;
        }
        else if ((month - i) == FEBRUARY) {
            if (leap == true) {
                *sec_month += DAYS_FEBRUARY_LEAP;
            }
            else {
                *sec_month += DAYS_FEBRUARY;
            }
        }
        else {
            *sec_month += MONTH_TO_SEC;
        }
    }
}

void calculate_day(int day, int *sec_day)
{
    for (int i = 0; i < (day - 1); i++) {
        *sec_day += DAY_TO_SEC; 
    }
}

int main(void)
{
    int result, date, ntime, hour, minute, second, day, month, year, difference;
    int sec_year = 0;
    int sec_month = 0;
    int sec_day = 0;
    bool leap;
    
    printf("\nInput date (HH:MM:SS DD.MM.YYYY): ");
    scanf("%d %d %d %d %d %d", &hour, &minute, &second, &day, &month, &year);
    
    calculate_year(year, &sec_year);
    leap = is_year_leap(year);
    
    if (month <= MONTHES_IN_YEAR) {
        calculate_month(month, &sec_month, leap);
    }
    else {
        printf("\nToo many monthes!!!");
        return 0;
    }
    
    if (day <= DAYS_IN_MONTH){
        calculate_day(day, &sec_day);
    }
    else {
        printf("\nToo many days!!!");
        return 0;
    }
    
    date = sec_year + sec_month + sec_day;
    ntime = (hour * HOUR_TO_SEC) + (minute * MINUTE_TO_SEC) + second + date;

    printf ("\nTime in seconds: %d", ntime);
    printf("\nUnix mktime(): %u", ntime + UNIX_TIME_OFFSET);
	
	return 1;
}
