#include <stdio.h>
#include <stdbool.h>

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

bool get_rate(int choice, float *rate)
{
    bool right = true;

    switch (choice) {
        case 'a':
            *rate = RATE_ONE;
            break;
        case 'b':
            *rate = RATE_TWO;
            break;
        case 'c':
            *rate = RATE_THREE;
            break;
        case 'd':
            *rate = RATE_FOUR;
            break;
        case 'q':
            *rate = 0.0f;
            break;
        default:
            right = false;
    }

    return right;
}

void choose(float *rate)
{
    char choice;
    bool right_choise = false;

    while (!right_choise) {
        printf("\n\n******************************************************************");
        printf("\nInput number which defines your desired tariff rate or action:");
        printf("\na) $8.75/h\t\tb) $9.33/h\nc) $10.00/h\t\td) $11.20/h\nq) Exit");
        printf("\n******************************************************************\n\n");
        scanf("%c", &choice);

        right_choise = get_rate(choice, rate);
    }
}

int main(void)
{
    int hours;
    float rate, charges, taxes, your_salary;

    while (1) {
        choose(&rate);
			
        if (rate == 0.0f) {
            break;
        }
        
        printf("\nInput number of work hours: \n\n");
        scanf("%d", &hours);

        if (hours <= STANDARD_WORKTIME) {
            charges = rate * (float)hours;
        }
        else {
            charges = (rate * STANDARD_WORKTIME) + ((float)hours - STANDARD_WORKTIME) * (rate * SALARY_OVERTIME);
        }
        
        if (charges < FIRST_TAX_BOUNDARY) {
            taxes = charges * TAX_300_DOLLARS;
        }
        else if ((charges > FIRST_TAX_BOUNDARY) && (charges < (FIRST_TAX_BOUNDARY + SECOND_TAX_BOUNDARY))) {
            taxes = (FIRST_TAX_BOUNDARY * TAX_300_DOLLARS) + ((charges - FIRST_TAX_BOUNDARY) * TAX_450_DOLLARS);
        }
        else {
            taxes = (FIRST_TAX_BOUNDARY * TAX_300_DOLLARS) + (SECOND_TAX_BOUNDARY * TAX_450_DOLLARS) + ((charges - (FIRST_TAX_BOUNDARY + SECOND_TAX_BOUNDARY)) * TAX_REST);
        }

        your_salary = charges - taxes;

        printf("\nYour salary: %0.2f", charges);
        printf("\nYour taxes: %0.2f", taxes);
        printf("\nYou've earned: %0.2f bucks\n", your_salary);
    }

    printf("\nExiting from the program...");
    return 0;
}
