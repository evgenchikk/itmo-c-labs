#include <stdio.h>

void showM1( int *m )
{
  int i;
  
  for (i = 0; i < 7; i++)
    printf("|%d  ", i);
  printf("|\n");
  for (i = 0; i < 7; i++)
    printf("|%d ", m[i]);
  printf("|");
}

void showM2( int m[2][2] )
{
  int i, j;
  
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    {
      printf("%d  ", m[i][j]);
      if (j == 1)
        printf("\n");
    }
}

void mulM( int m1[2][2], int m2[2][2] )
{
  int res[2][2], i, j, k;
  
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    {
      res[i][j] = 0;
      for (k = 0; k < 2; k++)
        res[i][j] += m1[i][k] * m2[k][j];
    }
  showM2(res);
}

int main( void )
{
  int m[7] = {10, 20, 30, 40, 50, 60, 70};
  int m1[2][2] = {{1, 2}, {3, 4}};
  int m2[2][2] = {{1, 0}, {0, 1}};
  
  showM1(m);
  printf("\n\n");
  printf("M1: \n");
  showM2(m1);
  printf("\n");
  printf("M2: \n");
  showM2(m2);
  printf("\n");
  printf("M1 x M2:\n");
  mulM(m1, m2);
  
  return 0;
}
