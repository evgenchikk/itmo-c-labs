#include <stdio.h>

#define MIN 1
#define MAX 10
#define BIT 1

int main( void )
{
  int x, res;
  
  printf("Input integer: ");
  scanf("%i", &x);
  res = MIN <= x && x <= MAX;
  printf("%i %s in %i..%i\n", x, res ? "is" : "is not", MIN, MAX); //Task 1
  
  printf("Input hex: ");
  scanf("%x", &x);
  printf("Bit №%d = %d", BIT, (x >> BIT) & 1); // Task 2
  
  
  return 0;
}
