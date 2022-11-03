#include <stdio.h>
#include <locale.h>
#include <float.h>
#include <stdbool.h>

#define ARRAY_SIZE    5u

static void copy_array(double target[], double array[], int size);
static void copy_ptr(double *target, double *array, int size);
static void copy_ptrs(double *target, double *array, double *end);

int main(void)
{
    double array[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    double target1[ARRAY_SIZE];
    double target2[ARRAY_SIZE];
    double target3[ARRAY_SIZE];
    
    copy_array(target1, array, ARRAY_SIZE);
    printf("\nNew target #1 array: %f %f %f %f %f", target1[0], target1[1], target1[2], target1[3], target1[4]);
    
    copy_ptr(target2, array, ARRAY_SIZE);
    printf("\nNew target #2 array: %f %f %f %f %f", target2[0], target2[1], target2[2], target2[3], target2[4]);

    copy_ptrs(target3, array, array + ARRAY_SIZE);
    printf("\nNew target #3 array: %f %f %f %f %f", target3[0], target3[1], target3[2], target3[3], target3[4]);
    
    return 0;
}

static void copy_array(double target[], double array[], int size)
{
    for (int i = 0; i < size; i++) {
        target[i] = array[i];
        printf("\nArray 1: %f", target[i]);
    }
}

static void copy_ptr(double *target, double *array, int size)
{
    for (int i = 0; i < size; i++, target++, array++) {
        *target = *array;
        printf("\nArray 2: %f", *target);
    }
}

static void copy_ptrs(double *target, double *array, double *end)
{
    while (array < end) {
        *(target++) = *(array++);
    }
}
