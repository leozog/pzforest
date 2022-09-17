#include "random.h"
#include <stdlib.h>

void rand_SEED(int a)
{
    srand(a);
}

int rand_int(int a, int b)
{
    return a + rand() % (b - a + 1);
}

double rand_float(double a, double b)
{
    return (double)rand()/(double)(RAND_MAX/a);
}