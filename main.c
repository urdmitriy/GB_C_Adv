#include <stdio.h>
#include "math.h"

/*
 *
 *
 *
 *
 */

typedef float (* f)(float x);

typedef struct {
    float x;
    float y;
} point_t;

typedef struct {
    point_t point[5];
} data_t;

float f1(float x) {

    return 0.6f * x + 3;
}

float f2(float x) {

    return (x - 2) * (x - 2) * (x - 2) - 1;
}

float f3(float x) {

    return 3.0f / x;
}

void find_intersection_point(float x1, float x2, float eps, f func1, f func2, float error_avr, point_t* point) {

    float delta_y = fabsf(func1(x1) - func2(x1));
    float step = (x2 - x1) * eps;
    for (float i = x1; i < x2; i += step) {
        float y_f1 = func1(i);
        float y_f2 = func2(i);
        float current_delta_y = fabsf(y_f1 - y_f2);

        if ((current_delta_y < delta_y) && (current_delta_y < error_avr)) {
            delta_y = current_delta_y;
            point->x = i;
            point->y = y_f1;
        }
    }
}

int main() {

    data_t data;

    find_intersection_point(-10, 0, 0.0001, f1, f3, 0.1, &data.point[0]);
    find_intersection_point(0, 5, 0.0001, f1, f3, 0.1, &data.point[1]);
    find_intersection_point(0, 5, 0.0001, f1, f2, 0.1, &data.point[2]);
    find_intersection_point(0, 5, 0.0001, f2, f3, 0.1, &data.point[3]);
    find_intersection_point(-5, 0, 0.0001, f2, f3, 0.1, &data.point[4]);

    for (int i = 0; i < 5; ++i) {
        printf("Point intersection #%d: \tx=%f,\ty=%f\n\r", i, data.point[i].x, data.point[i].y);
    }

    return 0;
}
