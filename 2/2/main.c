#include <stdio.h>
#include <math.h>

double z1( double alpha )
{
  return 2 * pow(sin(3 * M_PI - 2 * alpha), 2) * pow(cos(5 * M_PI + 2 * alpha), 2);
}

double z2( double alpha )
{
  return (0.25 - 0.25 * sin(2.5 * M_PI - 8 * alpha));
}

int main( void )
{
  double alpha;
  
  printf("Input alpha: ");
  scanf("%lf", &alpha);
  printf("z1(%g) = %lf\n", alpha, z1(alpha));
  printf("z2(%g) = %lf\n", alpha, z2(alpha));
  return 0;
}
