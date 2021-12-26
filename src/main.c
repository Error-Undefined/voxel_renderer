#include <stdlib.h>
#include <stdio.h>

#include "renderer/program_window.h"

int main(int argc, char** argv)
{
  s_program program;
  program.width = 640;
  program.height = 480;
  program.im_path = "assets/C24W.png";
  program.height_path = "assets/D24.png";

  int res_init = init_window(&program);
  if(res_init != 0)
  {
    fprintf(stderr, "Recieved error %d\n", res_init);
    terminate_program(&program);
    exit(res_init);
  }

  int res_loop = game_loop(&program);
  if(res_loop != 0)
  {
    fprintf(stderr, "Recieved error %d\n", res_init);
    terminate_program(&program);
    exit(res_init);
  }
  
  terminate_program(&program);
}
