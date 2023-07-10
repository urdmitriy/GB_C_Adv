#include <stdio.h>
#include <inttypes.h>

#define ARRAY_SIZE 32

typedef struct pack_array {
    uint32_t array[32]; // массив из 0 и 1
    uint32_t count0 : 8; // количество 0 в массиве
    uint32_t count1 : 8; // количество 1 в массиве
}pack_array_s;

void array2struct(int ar[], struct pack_array *ps)
{
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if(ar[i]==0){
            ps->count0++;
        } else
        {
            ps->count1++;
        }
        ps->array[i] = ar[i];
    }
}

void struct2array(int ar[], struct pack_array *ps)
{
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        ar[i] =  ps->array[i];
    }
}

int extractExp(float f) {
    union {
        float f;
        struct {
            uint32_t mantissa : 23;
            uint32_t exp : 8;
            uint32_t s : 1;
        } field;
    } fl;
    fl.f = f;
    return fl.field.exp;
}

int main() {

    int arr[] = {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                     0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                     0,1,0};
    pack_array_s pack_array;

    array2struct(arr, &pack_array);

    int arr_new[ARRAY_SIZE] = {0,};

    struct2array(arr_new,&pack_array);

    int i = extractExp(1.4f);

    return 0;
}
