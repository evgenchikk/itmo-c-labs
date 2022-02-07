#include <stdio.h>

int main( void )
{
  char str[100] = {0};
  int x;
  
  printf("Input string: ");
//  scanf("%s ", str);
  gets(str);
  printf("Input int: ");
  scanf("%i", &x);
  printf("\n\nString: %s\nInt: %i", str, x);
  
  return 0;
}
