#include <stdio.h>
#include "header.h"
#include "header.h"

int main( void )
{
  struct rec *r = createRec();
  printf("Perimeter of rectangle = %g\n", Perim(r));
  printf("Square of rectangle = %g\n", Square(r));
  
  return 0;
}
