#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

#define DEPOSIT_FOR_DAFNA    100u
#define PERCENT_FOR_DAFNA    0.1f
#define PERCENT_FOR_DEIDRA   0.05f

int main(void)
{
    float dafna = 0.0f;
    float deidra = 0.0f;
    int deidras_deposit = 100;
    
    do {
        dafna += DEPOSIT_FOR_DAFNA + (DEPOSIT_FOR_DAFNA * PERCENT_FOR_DAFNA);
        deidras_deposit += (deidras_deposit * PERCENT_FOR_DEIDRA);
        deidra += deidras_deposit;
    } while (deidra <= dafna);
    printf("\nDafna's deposit is %f", dafna);
    printf("\nDeidra's deposit is %f", deidra);
}
