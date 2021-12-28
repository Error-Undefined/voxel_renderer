#ifndef PROGRAM_WINDOW_H
#define PROGRAM_WINDOW_H

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "graphics/graphics.h"

#include "../image/image.h"
#include "../camera/camera.h"

struct s_program
{
  GLFWwindow* window;
  s_graphics g;

  int width, height;
  const char *im_path, *height_path;
  s_image im;
  s_height h_map;
  s_camera camera;

  s_image rendered_image;
};
typedef struct s_program s_program;

int init_window(s_program* p);

int game_loop(s_program* p);

void terminate_program(s_program* p);

#endif
