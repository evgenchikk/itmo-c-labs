#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

typedef struct {
  int x, y;
} point;

int NOD(int a, int b) //Алгоритм Евклида
{
  while (a != 0 && b != 0)
  {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return a + b;
}

int NOK(int a, int b)
{
  return a * b / NOD(a, b);
}

void ShowPoints(point *p)
{
  int i;
  
  for (i = 0; i < N; i++)
    printf("%i) (%i, %i)\n", i + 1, p[i].x, p[i].y);
}

void Fill(point *p)
{
  int i;
  
  for (i = 0; i < N; i++)
  {
    p[i].x = rand() % 25;
    p[i].y = rand() % 25;
  }
}


double *Func(point *p)
{
  int i, j;
  double *mas = malloc(sizeof(double) * N * (N - 1));

  for (i = 0; i < N; i++)
    for (j = 0; j < (N - 1); j++)
    {
      *(mas + i * (N - 1) + j) = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
    }

  return mas;
}


void ShowMas(double *mas)
{
  int i, j;
  
  for (i = 0; i < N; i++)
  {
    printf("\n");
    for (j = 0; j < (N - 1); j++)
      printf("%5.3g  ", *(mas + i * (N - 1) + j));
  }
}

int main( void )
{
  //int a, b;
  
  double *mas;
  point p[N];
  
  //printf("Input a: ");
  //scanf("%i", &a);
  //printf("Input b: ");
  //scanf("%i", &b);
  
  //printf("NOD = %i\n", NOD(a, b));
  //printf("NOK = %i\n", NOK(a, b));
  
  Fill(p);
  ShowPoints(p);
  mas = Func(p);
  ShowMas(mas);
  
  free(mas);
  printf("\n");
  return 0;
}
