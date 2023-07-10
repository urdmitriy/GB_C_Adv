#include <stdio.h>
#include "LIB/test.h"
#include <math.h>

/*2. Создайте функцию которая считает корни квадратного уравнения (коэффициенты A,B,C просим ввести пользователя
 * через scanf). Напишите вторую функцию, которая будет проверять корректность корней при разных коэффициентах.
 * Постарайтесь учесть все варианты (когда корней нет, когда корень только один (одинаковые корни), когда корней два)
3. Создайте библиотеку из тестирующей функции и/или функции замеряющей время.
*/


void calculate(int a, int b, int c, answer_s *answer)
{
    if (a==0) return;
    int d = b * b - 4 * a *c;

    if (d>0)
    {
        answer->count_roots = 2;
        answer->x1 = (-1 * b + sqrt(d)) / (2 * a);
        answer->x2 = (-1 * b - sqrt(d)) / (2 * a);
        return;
    }
    else if (d == 0)
    {
        answer->count_roots = 1;
        answer->x1 = (-1 * b) / (2 * a);
        return;
    }
    else
    {
        answer->count_roots = 0;
        return;
    }
}

int main() {
    int a=0, b=0, c=0;

    printf("Enter a, b, c\n\r");
    scanf("%d %d %d", &a, &b, &c);

    answer_s answer;
    calculate(a, b, c, &answer);

    if (answer.count_roots == 2)
    {
        printf("Answer: X1 = %0.2f, X2 = %0.2f\n\r", answer.x1, answer.x2);
    }
    else if (answer.count_roots == 1)
    {
        printf("Answer: X = %0.2f\n\r", answer.x1);
        return 1;
    }
    else
    {
        printf("Answer: No roots\n\r");
        return 0;
    }

    test(calculate);

    return 0;
}
