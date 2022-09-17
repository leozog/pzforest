#include "perlin.h"
#include "random.h"
#include "vec3.h"
#include "img.h"
#include "config.h"


#include <stdlib.h>
#include <math.h>
#include <time.h>

#define W 1024
#define H 1024

int main(int argc, const char **argv)
{
    float freq = atof(argv[2]);
    int depth = atoi(argv[3]);

    Img img = img_new(W, H, 3);

    ivec3 tab[4];
    tab[0] = ivec3_set(40, 44, 76);
    tab[1] = ivec3_set(80, 60, 75);
    tab[2] = ivec3_set(128, 200, 125);
    tab[3] = ivec3_set(200, 230, 140);

    perlin_SEED = time(NULL);
    rand_SEED(perlin_SEED);

    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            int a = perlin_get2d(j, i, freq, depth) * 255;
            img_set(&img, j, i, tab[ivec3_get_closest(ivec3_set(a, a, a), tab, 4)]);
        }
    }
    img_write(&img, argv[1]);
    img_free(&img);

    return 0;
}