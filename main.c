#include <stdio.h>

/*
 *
 *
 *
 *
 */

typedef void(* f)(float x);

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
    for (float i = x1; i < x2; i += eps) {

    }
}

int main() {

    return 0;
}
