#include <stdio.h>

#include "renderer/program_window.h"

int main()
{
  int res = init_window();

  printf("Returned with code %d\n", res);
}
