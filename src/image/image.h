#ifndef IMAGE_H
#define IMAGE_H

struct color
{
    unsigned char R, G, B;
};
typedef struct color s_color;

struct point_i
{
    int x, y;
};
typedef struct point_i s_point_i;

struct point_f
{
    float x, y;
};
typedef struct point_f s_point_f;

struct image
{
    s_color* image_data;
    s_point_i size;
}; 
typedef struct image s_image;

struct height
{
    unsigned char* height;
    s_point_i size;    
};
typedef struct height s_height;

int load_image(const char* path, s_image* im);
int load_height(const char* path, s_height* h);

#endif
