#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"

struct rec *createRec( void )
{
  struct rec *r = malloc(sizeof(struct rec));
  
  printf("Input x, y for 1st point: ");
  scanf("%lf, %lf", &(r->p1.x), &(r->p1.y));
  
  printf("Input x, y for 2nd point: ");
  scanf("%lf, %lf", &(r->p2.x), &(r->p2.y));
  
  printf("Input x, y for 3rd point: ");
  scanf("%lf, %lf", &(r->p3.x), &(r->p3.y));
  
  return r;
}

double Perim( const struct rec *r )
{
  return 2 * (sqrt((r->p1.x - r->p2.x) * (r->p1.x - r->p2.x) + (r->p1.y - r->p2.y) * (r->p1.y - r->p2.y))
              + sqrt((r->p2.x - r->p3.x) * (r->p2.x - r->p3.x) + (r->p2.y - r->p3.y) * (r->p2.y - r->p3.y)));
}

double Square( const struct rec *r )
{
  return sqrt((r->p1.x - r->p2.x) * (r->p1.x - r->p2.x) + (r->p1.y - r->p2.y) * (r->p1.y - r->p2.y))
  * sqrt((r->p2.x - r->p3.x) * (r->p2.x - r->p3.x) + (r->p2.y - r->p3.y) * (r->p2.y - r->p3.y));
}
