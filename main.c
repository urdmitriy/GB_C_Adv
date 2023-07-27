#include <stdio.h>
#include "math.h"

/*
 *
 *
 *
 *
 */

typedef float (* f)(float x);

float f1(float x) {
    return 0.6f * x + 3;
}

float f2(float x) {
    return (x - 2) * (x - 2) * (x - 2) - 1;
}

float f3(float x) {
    return 3.0f / x;
}

float find_root(float x1, float x2, float eps, f func) {
    float delta_x = fabsf(func(x1) - func(x2));
    float root = 0;
    for (float i = x1; i < x2; i += eps) {

    }
    return root;
}

int main() {
    float root = find_root(-5,5,0.0001,f1);
    printf("root = %f", root);
    return 0;
}
