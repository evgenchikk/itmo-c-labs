#include <stdio.h>
#include "14.h"
//typedef unsigned char byte;


void PutPixel( byte Frame[H][W][3], int x, int y, byte red, byte green, byte blue )
{
  Frame[y][x][0] = blue;
  Frame[y][x][1] = green;
  Frame[y][x][2] = red;
}


int GetCell( byte Frame[H][W][3], int x, int y )
{
  if (Frame[y][x][2] != 0)
    return 1;
  else
    return 0;
}

int GetNeighbours( byte Frame[H][W][3], int x, int y )
{  
  return GetCell(Frame, (x - 1 + W) % W, (y - 1 + H) % H) +
  GetCell(Frame, x, (y - 1 + H) % H) +
  GetCell(Frame, (x + 1 + W) % W, (y - 1 + H) % H) +
  GetCell(Frame, (x - 1 + W) % W, y) +
  GetCell(Frame, (x + 1 + W) % W, y) +
  GetCell(Frame, (x - 1 + W) % W, (y + 1 + H) % H) +
  GetCell(Frame, x, (y + 1 + H) % H) +
  GetCell(Frame, (x + 1 + W) % W, (y + 1 + H) % H);
}

void SetCell( byte Frame[H][W][3], int x, int y, int val )
{
  if (val == 0)
    PutPixel(Frame, x, y, 0, 0, 0);
  else
    PutPixel(Frame, x, y, 255, 0, 0);
}

void CalcNextStep( byte A[H][W][3], byte B[H][W][3] )
{
  int x, y;
  
  for (y = 0; y < H; y++)
    for (x = 0; x < W; x++)
      if (GetNeighbours(A, x, y) == 3)
        SetCell(B, x, y, 1);
      else if (GetCell(A, x, y) && (GetNeighbours(A, x, y) == 2))
        SetCell(B, x, y, 1);
      else
        SetCell(B, x, y, 0);
}
