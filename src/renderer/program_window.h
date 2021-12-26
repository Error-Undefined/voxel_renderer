#ifndef PROGRAM_WINDOW_H
#define PROGRAM_WINDOW_H

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "../image/image.h"
struct s_program
{
  GLFWwindow* window;
  int width, height;
  const char* im_path;
  image im;
};
typedef struct s_program s_program;

int init_window(s_program* p);

int game_loop(s_program* p);

void terminate_program(s_program* p);

#endif
