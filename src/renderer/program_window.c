#include <stdio.h>

#include "../../libs/glad/glad.h"
#include <GLFW/glfw3.h>

#include "program_window.h"

int init_window()
{
  int width = 640;
  int height = 480;

  printf("Hello from the other fiiiiile\n");
  // Init glfw
  if (!glfwInit())
  {
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow(640, 480, "Test title", NULL, NULL);
  
  if(!window)
  {
    return -2;
  }
  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
  {
    return -3;
  }
  glViewport(0,0, width, height);

  while(!glfwWindowShouldClose(window))
  {
    glfwPollEvents();

    glClearColor(0.2f,0.6f,0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }
  
  glfwTerminate();
  return 0;
}

