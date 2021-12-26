#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "../../libs/stb/stb_image.h"

#include "image.h"

int load_image(const char* path, image* im)
{
    int img_channels;
    im->image_data = (color*) stbi_load(path, &im->size.x, &im->size.y, &img_channels, 0);
    if(im->image_data == NULL)
    {
        return -1;
    }
    return 0;
}

