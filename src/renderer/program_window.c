#include <stdio.h>

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "program_window.h"

int init_window(s_program* p)
{
  printf("Hello from the other fiiiiile\n");
  // Init glfw
  if (!glfwInit())
  {
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow(p->width, p->height, "Test title", NULL, NULL);
  
  if(!window)
  {
    return -2;
  }
  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    return -3;
  }
  glViewport(0,0, p->width, p->height);
  
  p->window = window;
  load_image(p->im_path, &p->im);

  return 0;
}

int game_loop(s_program* p)
{
  while(!glfwWindowShouldClose(p->window))
  {
    glfwPollEvents();

    glClearColor(0.2f,0.6f,0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(p->window);
  }

  return 0;
}

void terminate_program(s_program* p)
{
  glfwTerminate();
  p->window = NULL;
}
