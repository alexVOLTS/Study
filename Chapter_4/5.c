#include <stdio.h>

int main(void)
{
    float speed;
    float size;

    printf("Input download speed in megabytes in second:");
    scanf("%f", &speed);

    printf("\nInput file size in megabytes:");
    scanf("%f", &size);

    float speed_bit = speed * 8;
    float download = size / speed;

    printf("\nAt download speed %f megabit in second file with size of %.2f megabyte downloads for %.2f seconds", speed_bit, size, download);
    return 0;
}
