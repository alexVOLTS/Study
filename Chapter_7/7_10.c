#include <stdio.h>
#include <stdbool.h>

#define FIRST_TAX           0.15f
#define SECOND_TAX          0.28f
#define LONE_WOLF           17850.0f
#define FAMILY_MAIN         23900.0f
#define MARRIED_TOGETHER    29750.0f
#define MARRIED_ALONE       14875.0f



bool get_status(int choice, float *status)
{
    bool right = true;

    switch (choice) {
        case 1:
            *status = LONE_WOLF;
            break;
        case 2:
            *status = FAMILY_MAIN;
            break;
        case 3:
            *status = MARRIED_ALONE;
            break;
        case 4:
            *status = MARRIED_TOGETHER;
            break;
        default:
            right = false;
            break;
    }

    return right;
}

void choose(float *status)
{
    int choice;
    bool right_choise = false;

    while (!right_choise) {
        printf("\n\n---------------------------------------------------------------");
        printf("\nChoose your category: ");
        printf("\n1) LONE_WOLF\t\t2) MAIN IN THAT GODDAMN FAMILY\n3) MARRIED AND EVERTHNG 'S GOOD\t\t4) MARRIED N :(\n");
        printf("\n---------------------------------------------------------------\n\n");
        scanf("%d", &choice);

        right_choise = get_status(choice, status);
    }
}

int main(void)
{
    int salary;
    float status, tax;
    
    while (1){
        choose(&status);
        
        if (status == 0.0f){
            break;
        }
        
        printf("\nInput your salary: \n");
        scanf("%d", &salary);
        
        if ((float)salary <= status){
            tax = (float)salary * FIRST_TAX;
        }
        else {
            tax = (status * FIRST_TAX) + (salary - status)*SECOND_TAX;
        }
        
        printf("\nYou need to pay %.2f $$$ to sponsor dirty capitalists", tax);
    }
    
    printf("\nExiting from the program...");
    
    return 0;
}
