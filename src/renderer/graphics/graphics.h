#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../../image/image.h"

struct graphics
{
    GLFWwindow* window;
    const GLFWvidmode* mode;
    GLuint texture_id;
    GLuint vao;
    GLuint shader;

    s_image image;
};

typedef struct graphics s_graphics;

int create_graphics(s_graphics* g, int w, int h);

void render_graphics(s_graphics* g);

#endif
