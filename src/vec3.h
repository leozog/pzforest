#pragma once

typedef struct ivec3_s
{
    int x, y, z;
} ivec3;

ivec3 ivec3_set(int x, int y, int z);
ivec3 ivec3_add(ivec3 a, ivec3 b);
ivec3 ivec3_sub(ivec3 a, ivec3 b);
ivec3 ivec3_mul(ivec3 a, double b);
double ivec3_len(ivec3 a);
int ivec3_get_closest(ivec3 a, ivec3 b[], int n);