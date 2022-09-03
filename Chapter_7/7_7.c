#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define SALARY                 10.0f
#define SALARY_OVERTIME        15.0f
#define TAX_300_DOLLARS        0.15f
#define TAX_450_DOLLARS        0.2f
#define FIRST_TAX_BOUNDARY     300.0f
#define SECOND_TAX_BOUNDARY    150.0f
#define TAX_REST               0.25f
#define STANDARD_WORKTIME      40.0f

int main(void)
{
    int hours;
    float charges, taxes, your_salary;
    
    printf("\nInput number of work hours: ");
   
    while((scanf("%d", &hours)) == 1){
        
        if(hours <= STANDARD_WORKTIME){
            charges = SALARY * (float)hours;
        }
        else{
            charges = (SALARY * STANDARD_WORKTIME) + (((float)hours - STANDARD_WORKTIME) * SALARY_OVERTIME);
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
    }
    printf("\n\n\n\t\t\t\t\tProgram ends here...");
    
    return 0;
}
