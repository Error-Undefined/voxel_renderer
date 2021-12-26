#ifndef IMAGE_H
#define IMAGE_H

struct color
{
    unsigned char R, G, B;
};
typedef struct color color;

struct point_i
{
    int x, y;
};
typedef struct point_i point_i;

struct image
{
    color* image_data;
    point_i size;
}; 
typedef struct image image;

int load_image(const char* path, image* im);

#endif
