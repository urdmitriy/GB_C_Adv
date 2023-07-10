//
// Created by urdmi on 10.07.2023.
//

#ifndef GB_C_ADV_TEST_H
#define GB_C_ADV_TEST_H

#include <assert.h>

typedef struct {
    int count_roots;
    double x1;
    double x2;
} answer_s;

void test(void (*app)(int, int, int, answer_s*));

#endif //GB_C_ADV_TEST_H
