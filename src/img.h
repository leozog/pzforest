#pragma once
#include "vec3.h"

typedef struct Img_s
{
    int w, h, BPP;
    unsigned char *data;
} Img;

void img_set(Img *img, int x, int y, ivec3 c);
ivec3 img_get(Img *img, int x, int y);
ivec3 img_get_avg(Img *img, int x, int y, int r);
Img img_load(char *name);
void img_write(Img *img, const char *name);
void img_free(Img *img);
Img img_new(int w, int h, int BPP);
Img img_cpy(Img *img);