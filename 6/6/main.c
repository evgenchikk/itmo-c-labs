#include <stdio.h>
#include <stdlib.h>

void ShowMas( char *mas )
{
  int i;
  for (i = 0; i < 4; i++)
    printf("%s%c", i == 0 ? "" : ", ", *(mas + i));
}

int main( void )
{
  char *mas;
  
  mas = (char *)malloc(sizeof(char) * 4);
  mas[0] = 'a';
  mas[1] = 'b';
  mas[2] = 'c';
  mas[3] = 'd';
  ShowMas(mas);
  
  free(mas);
  return 0;
}
