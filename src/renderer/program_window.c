#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "program_window.h"

#include "../image/image.h"

static void init_camera(s_program* p)
{
  p->camera.angular_speed = 0;
  p->camera.distance = 300;
  p->camera.scale_height = 120;
  p->camera.height = 50;
  p->camera.horizon = 120;
  p->camera.speed = 0;

  p->camera.center = (s_point_i) {0,0};
}

int init_window(s_program* p)
{

  load_image(p->im_path, &p->im);
  load_image(p->im_path, &p->rendered_image);
  load_height(p->height_path, &p->h_map);

  p->g.image = p->rendered_image;

  init_camera(p);

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

static void draw_line(s_program* p, s_color* color, int height, int x)
{
  for(int i = height; i >= 0; i--)
  {
    //p->rendered_image.image_data[x*p->rendered_image.size.y+i].R = color->R;
    //p->rendered_image.image_data[x*p->rendered_image.size.y+i].G = color->G;
    //p->rendered_image.image_data[x*p->rendered_image.size.y+i].B = color->B;
  }
}

static int i;

static void render_view(s_program* p)
{
  /*
  for(int z = p->camera.distance; z > 1; z--)
  {
    s_point_i left, right;
    left.x = -z + p->camera.center.x;
    left.y = z + p->camera.center.y;
    right.x = z + p->camera.center.x;
    right.y = z +p->camera.center.y;

    double dx = 1.0*(right.x - left.x) / p->width;

    for(int i = 0; i < p->width; i++)
    {
      int h_map_index = ((left.x % p->h_map.size.x)  + (left.y * p->h_map.size.y));
      double height_on_screen = (p->camera.height - p->h_map.height[h_map_index])*1.0/z * p->camera.scale_height + p->camera.horizon;
      if (height_on_screen < 0)  
        printf("%lf\n", height_on_screen);
      draw_line(p, &p->im.image_data[h_map_index], (int) height_on_screen, i);
      // Draw a vertical line
      
      left.x += dx;
    }
  }
  */
  
  //p->g.image.image_data[i] = (s_color) {255,0,0}; 
  //i = (i % (p->g.image.size.x * p->g.image.size.y));
  //i = i+1;
}

int game_loop(s_program* p)
{
  glfwSetFramebufferSizeCallback(p->window, framebuffer_size_callback);

  int t0 = time(NULL);
  int t1 = time(NULL);

  while(!glfwWindowShouldClose(p->window))
  {
    render_view(p);

    render_graphics(&p->g);

    glfwSwapBuffers(p->window);
    glfwPollEvents();

    p->camera.center.x = (p->camera.center.x + 1) % p->rendered_image.size.x;
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
