#include <stdio.h>

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "program_window.h"

int init_window(s_program* p)
{

  load_image(p->im_path, &p->im);
  load_height(p->height_path, &p->h_map);
  p->g.image = p->im;

  int res = create_graphics(&p->g, p->width, p->height);

  p->window = p->g.window;
  
  if(res != 0)
  {
    fprintf(stderr, "Threw error %d\n", res);
  }

  return 0;
}

static void framebuffer_size_callback(GLFWwindow *window, int w, int h)
{
  glViewport(0,0,w,h);
}

int game_loop(s_program* p)
{
  glfwSetFramebufferSizeCallback(p->window, framebuffer_size_callback);

  while(!glfwWindowShouldClose(p->window))
  {
    glfwSwapBuffers(p->window);
    render_graphics(&p->g);
    glfwPollEvents();
  }

  return 0;
}

void terminate_program(s_program* p)
{
  /*
  FILE* fp;
  fp = fopen("load.ppm", "w+");

  fputs("P3\n", fp);
  fprintf(fp, "%d %d\n", p->im.size.x, p->im.size.y);
  for (int i = 0; i < p->im.size.x * p->im.size.y; i++)
  {
    fprintf(fp,"%d %d %d\n", p->im.image_data[i].B, p->im.image_data[i].R, p->im.image_data[i].G);
  }
  fclose(fp);
  */

  glfwTerminate();
  p->window = NULL;
}
