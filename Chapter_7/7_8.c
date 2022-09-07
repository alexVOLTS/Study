#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define SALARY_OVERTIME        1.5f
#define TAX_300_DOLLARS        0.15f
#define TAX_450_DOLLARS        0.2f
#define FIRST_TAX_BOUNDARY     300.0f
#define SECOND_TAX_BOUNDARY    150.0f
#define TAX_REST               0.25f
#define STANDARD_WORKTIME      40.0f
#define RATE_ONE               8.75f
#define RATE_TWO               9.33f
#define RATE_THREE             10.00f
#define RATE_FOUR              11.20f

float rate;

float choose()
{
    int choice;
    printf("\n******************************************************************");
    printf("\nInput number which defines your desired tariff rate or action:");
    printf("\n1) $8.75/h\t\t2) $9.33/h\n3) $10.00/h\t\t4) $11.20/h\n5) Exit");
    printf("\n******************************************************************\n\n");
    scanf("%d", &choice);
        
    switch(choice){
        case 1:
            rate = RATE_ONE;
            break;
        case 2:
            rate = RATE_TWO;
            break;
        case 3:
            rate = RATE_THREE;
            break;
        case 4:
            rate = RATE_FOUR;
            break;
        case 5:
            printf("\nExiting from the program...");
            rate = 0;
            break;
        default:
            printf("\nYou must choose from 5 different variants");
    }
    return rate;
}

int main(void)
{
    int hours;
    float charges, taxes, your_salary;

    choose();
    
    if(rate == 0){
        return 0;
    }
    
    printf("\nInput number of work hours: \n\n");
    
    while((scanf("%d", &hours)) == 1){
        if(hours <= STANDARD_WORKTIME){
            charges = rate * (float)hours;
        }
        else{
            charges = (rate * STANDARD_WORKTIME) + ((float)hours - STANDARD_WORKTIME) * (rate * SALARY_OVERTIME);
        }
        
        if(charges < FIRST_TAX_BOUNDARY){
            taxes = charges * TAX_300_DOLLARS;
        }
        else if((charges > FIRST_TAX_BOUNDARY) && (charges < (FIRST_TAX_BOUNDARY + SECOND_TAX_BOUNDARY))){
            taxes = (FIRST_TAX_BOUNDARY * TAX_300_DOLLARS) + ((charges - FIRST_TAX_BOUNDARY) * TAX_450_DOLLARS);
        }
        else{
            taxes = (FIRST_TAX_BOUNDARY * TAX_300_DOLLARS) + (SECOND_TAX_BOUNDARY * TAX_450_DOLLARS) + ((charges - (FIRST_TAX_BOUNDARY + SECOND_TAX_BOUNDARY)) * TAX_REST);
        }
        
        your_salary = charges - taxes;
        
        printf("\nYour salary: %0.2f", charges);
        printf("\nYour taxes: %0.2f", taxes);
        printf("\nYou've earned: %0.2f bucks", your_salary);
        printf("\n\nInput number of work hours: ");
        
        choose(&rate);
        if(rate == 0){
        return 0;
        }
        printf("\nInput number of work hours: \n\n");
    }
    printf("\nExiting from the program...");
    
    return 0;
}
