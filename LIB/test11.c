//
// Created by urdmi on 10.07.2023.
//

#include "test.h"

void test(void (*app)(int, int, int, answer_s*))
{
    answer_s answer;
    (*app)(1, 3, -4, &answer);

    assert(answer.count_roots == 2);
    assert(answer.x1 == 1);
    assert(answer.x2 == -4);
}