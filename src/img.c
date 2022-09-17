#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

#include "img.h"
#include "vec3.h"

void img_set(Img *img, int x, int y, ivec3 c)
{
    img->data[y * img->w * img->BPP + x * img->BPP + 0] = (unsigned char)c.x;
    img->data[y * img->w * img->BPP + x * img->BPP + 1] = (unsigned char)c.y;
    img->data[y * img->w * img->BPP + x * img->BPP + 2] = (unsigned char)c.z;
}

ivec3 img_get(Img *img, int x, int y)
{
    ivec3 a;
    a.x = img->data[y * img->w * img->BPP + x * img->BPP + 0];
    a.y = img->data[y * img->w * img->BPP + x * img->BPP + 1];
    a.z = img->data[y * img->w * img->BPP + x * img->BPP + 2];
    return a;
}

ivec3 img_get_avg(Img *img, int x, int y, int r)
{
    ivec3 out = {0, 0, 0};
    int n = 0;
    for(int i = y - r; i <= y + r; i++)
    {
        for(int j = x - r; j <= x + r; j++)
        {
            if(x >= 0 && x < img->w && y >= 0 && y < img->h)
            {
                int k = i - y;
                int l = j - x;
                if(k * k + l * l <= r * r)
                {
                    out = ivec3_add(out, img_get(img, j, i));
                }
                n++;
            }
        }
    }
    if(n == 0) return out;
    return ivec3_mul(out, (double)1/n);
}

Img img_load(char *name)
{
    Img img;
    img.data = stbi_load(name, &img.w, &img.h, &img.BPP, 0);
    return img;
}

void img_write(Img *img, const char *name)
{
    stbi_write_png(name, img->w, img->h, img->BPP, img->data, img->w * img->BPP);
}

void img_free(Img *img)
{
    free(img->data);
    img->data = NULL;
}

Img img_new(int w, int h, int BPP)
{
    Img new;
    new.w = w;
    new.h = h;
    new.BPP = BPP;
    new.data = malloc(w * h * BPP * sizeof(char));
    if(!new.data) exit(-1);
    return new;
}

Img img_cpy(Img *img)
{
    Img new = img_new(img->w, img->h, img->BPP);
    int size = img->w * img->h * img->BPP;
    for(int i = 0; i < size; i++)
    {
        new.data[i] = img->data[i];
    }
    return new;
}