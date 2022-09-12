#include <stdio.h>
#include <stdbool.h>

bool input(float *x, float *y)
{
    float a, b;
    
    printf("\nInput first number: ");
    
    if (scanf("%f", &a) != 1) {
        printf("\n%c is not a number", a);
        return true;
    }
    else {
        *x = a;
    }
    
    printf("\nInput second number: ");
    
    if (scanf("%f", &b) != 1) {
        printf("\n%c is not a number", b);
        return true;
    }
    else {
        *y = b;
    }
    
    return false;
}

bool get_operation(int choice, float *result)
{
    float x, y;
    bool right;
    
    switch (choice) {
        case 'a':
            input(&x, &y);
            *result = x + y;
            break;  
        case 'b':
            input(&x, &y);
            *result = x - y;
            break;
        case 'c':
            input(&x, &y);
            *result = x * y;
            break;
        case 'd':
            input(&x, &y);
            *result = x / y;
            break;
        case 'q':
            *result = 0.0f;
            right = true;
            break;
        default:
            right = true;
            break;
    }
    
    return right;
}

void choose(float *result)
{
    char choice;
    bool right_choise = false;

    while (!right_choise) {
        printf("\n\n♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂");
        printf("\nChoose mathematical operation:");
        printf("\na) addition\t\tb) subtraction\nc) multiplication\td) division\nq) fuck mathematics");
        printf("\n♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂♂\n\n");
        scanf("%c", &choice);
        
        right_choise = get_operation(choice, result);
    }
}

int main(void)
{
    float result;
    bool check;
    
    while (1){
        choose(&result);
        
        if (result == 0.0f) {
            break;
        }
        printf("\n\nResult is: %.2f", result);
    }
    printf("\nNo, you! Math is the best!");
    
    return 0;
}
