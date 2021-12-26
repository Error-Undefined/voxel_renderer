#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../libs/stb/stb_image.h"

#include "image.h"

int load_image(const char* path, s_image* im)
{
    int img_channels;
    stbi_set_flip_vertically_on_load(0);
    im->image_data = (s_color*) stbi_load(path, &im->size.x, &im->size.y, &img_channels, 3);
    if(im->image_data == NULL)
    {
        return -1;
    }
    return img_channels;
}

int load_height(const char* path, s_height* h)
{
    int img_channels;
    stbi_set_flip_vertically_on_load(0);
    h->height = (unsigned char*) stbi_load(path, &h->size.x, &h->size.y, &img_channels, 0);
    if(h->height == NULL)
    {
        return -1;
    }
    return 0;
}
