#include <stdio.h>
#include <stdbool.h>

#define ARTICHOKES_PRICE         2.05f
#define BEETROOT_PRICE           1.15f
#define CARROT_PRICE             1.09f
#define DISCOUNT                 0.95f
#define DISCOUNT_BOUNDARY        100.0f
#define DELIVERY_COST_FIVE       6.50f
#define DELIVERY_COST_TWENTY     14.0f
#define DELIVERY_ADDITIONNALY    0.50f


bool get_weight(char choice, float *weight_artichokes, float *weight_beetroot, float *weight_carrot, float *price, bool *purchase)
{
    bool right = true;
    float vegetable = 0.0f;

    switch (choice) {
        case 'a':
            printf("\nInput weight in pounds: ");
            scanf("%f", &vegetable);
            
            *weight_artichokes += vegetable;
            
            printf("\nYou've chosen %.2f pounds of artichokes", *weight_artichokes);
            
            *price += ARTICHOKES_PRICE;
            *purchase = false;
            break;
        case 'b':
            printf("\nInput weight in pounds: ");
            scanf("%f", &vegetable);
            
            *weight_beetroot += vegetable;
            
            printf("\nYou've chosen %.2f pounds of beetroot", *weight_beetroot);
            
            *price += BEETROOT_PRICE;
            *purchase = false;
            break;
        case 'c':
            printf("\nInput weight in pounds: ");
            scanf("%f", &vegetable);
            
            *weight_carrot += vegetable;
            
            printf("\nYou've chosen %.2f pounds of carrot", *weight_carrot);
            
            *price += CARROT_PRICE;
            *purchase = false;
            break;
        case 'q':
            printf("\nPuchase finished");
            
            *purchase = true;
            break;
        default:
            right = false;
            *purchase = false;
            break;
    }

    return right;
}

void choose(float *weight_artichokes, float *weight_beetroot, float *weight_carrot, float *price, float *weight, bool *purchase)
{
    char choice;
    bool right_choise = false;

    while (!right_choise) {
        printf("\n\n---------------------------------------------------------------");
        printf("\nChoose product weight: ");
        printf("\na) Artichokes\t\tb) Beetroot\nc) Carrot\t\tq) Complete order");
        printf("\n---------------------------------------------------------------\n");
        scanf("%c", &choice);

        right_choise = get_weight(choice, weight_artichokes, weight_beetroot, weight_carrot, price, purchase);
        
        (*weight) = (*weight_artichokes) + (*weight_beetroot) + (*weight_carrot);
        
        printf("\nTotal weight is: %.2f pounds", *weight);
    }
}

void calculation(float price, float *weight, float *sum)
{
    if (*weight <= 5.0f) {
        *sum = DELIVERY_COST_FIVE + (price * *weight);
    }
    else if (*weight > 5.0f && *weight <= 20.0f) {
        *sum = DELIVERY_COST_TWENTY + (price * *weight);
    }
    else {
        *sum = DELIVERY_COST_TWENTY + (DELIVERY_ADDITIONNALY * (*weight - 20.0f)) + (price * *weight);
    }
    
    printf("\nSubtotal: %.2f", *sum);
}

void calculation_discount(float *sum)
{
    float discount_total = 0.0f;
    float total;
    
    if ((*sum) > DISCOUNT_BOUNDARY) {
        total = (*sum) * DISCOUNT;
        discount_total = (*sum) - total;
        printf("\nDiscount is: %.2f$$$", discount_total);
    }
    else {
        total = *sum;
    }
    
    printf("\nSubtotal including discount: %.2f$$$", total);
}

int main(void)
{
    bool purchase = false;
    float weight_artichokes = 0.0f;
    float weight_beetroot = 0.0f;
    float weight_carrot = 0.0f;
    float price = 0.0f;
    float sum, weight;
    
     while (!purchase) {
            choose(&weight_artichokes, &weight_beetroot, &weight_carrot, &price, &weight, &purchase);
        }
        
    if (weight == 0.0f) {
        printf("\n\nYou haven't picked up any vegatables. Are you a vegetable?");
        return 0;
    }
        
    calculation(price, &weight, &sum);
    calculation_discount(&sum);
    
    return 0;
}
