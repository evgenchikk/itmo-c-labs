#include <stdio.h>

#define MAX 50

void GetStr( char *str, int max )
{
  int i = 0, ch;
  
  while ((ch = getchar()) != '\n')
    if (str != NULL && i < max - 1)
      str[i++] = ch;
  if (str != NULL && i < max)
    str[i] = 0;
}

int CountNum( char *str )
{
  int res = 0;
  
  while (*str != 0)
  {
    if (*str >= 48 && *str <= 57)
      res++;
    str++;
  }
  return res;
}

int CountLet( char *str )
{
  int res = 0;
  
  while (*str != 0)
  {
    if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
      res++;
    str++;
  }
  return res;
}

void Cost( void )
{
  int mins, price, uplim, final;
  
  printf("Input mins, price per month and increased rate: ");
  scanf("%i %i %i", &mins, &price, &uplim);
  
  if (uplim < (double)price / 499)
  {
    printf("Uncorrect. Increased rate must be more expesive\n");
    return;
  }
  
  if (mins - 499 >= 0)
    final = (mins - 499) * uplim + price;
  else
    final = price;
  
  printf("Final cost: $%i\n", final);
}

int main( void )
{
  char str[MAX];
  
  printf("Input string: ");
  GetStr(str, MAX);
  printf("Count of letters: %i\n", CountLet(str));
  printf("Count of numbers: %i\n", CountNum(str));
  
  Cost();
  
  return 0;
}
