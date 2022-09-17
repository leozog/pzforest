#include "vec3.h"
#include "math.h"

ivec3 ivec3_set(int x, int y, int z)
{
    ivec3 a;
    a.x = x;
    a.y = y;
    a.z = z;
    return a;
}

ivec3 ivec3_add(ivec3 a, ivec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

ivec3 ivec3_sub(ivec3 a, ivec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

ivec3 ivec3_mul(ivec3 a, double b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

double ivec3_len(ivec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int ivec3_get_closest(ivec3 a, ivec3 b[], int n)
{
    int o;
    double d = INFINITY;
    for(int i = 0; i < n; i++)
    {
        double t = ivec3_len(ivec3_sub(a, b[i]));
        if(t < d)
        {
            o = i;
            d = t;
        }
    }
    return o;
}