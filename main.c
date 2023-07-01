#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

void Swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void Get_ptr_array(int * array, int ** array_ptr)
{
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array_ptr[i] = array + i;
        printf("Address element %d: %p, value: %d\n\r", i, array_ptr[i], *array_ptr[i]);
    }
}

void SortPointers(int** array_ptr)
{
    for (int i = 0; i < ARRAY_SIZE-1; ++i) {
        for (int j = 0; j < ARRAY_SIZE-1; ++j) {
            if (*array_ptr[j] > *array_ptr[j+1])
            {
                int* ptemp = array_ptr[j];
                array_ptr[j] = array_ptr[j+1];
                array_ptr[j+1] = ptemp;
            }
        }
    }
}

int main() {

    //===Задание 1===

    int a = 10, b=20;

    printf("a=%d, b=%d\n\r", a, b);

    Swap(&a, &b);

    printf("a=%d, b=%d\n\r", a, b);

    //===Задание 2===

    int* array = malloc(sizeof (int) * ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        *(array+i) = ARRAY_SIZE - i;
    }
    printf("\n\r");

    int* array_ptr[ARRAY_SIZE];

    Get_ptr_array(array, array_ptr);

    //===Задание 3===

    SortPointers(array_ptr);

    printf("Sorted array:\n\r");

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("Address element %d: %p, value: %d\n\r", i, array_ptr[i], *array_ptr[i]);
    }

    return 0;
}
