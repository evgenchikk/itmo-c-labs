#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bitrw.h"

static int accum, pos;
static FILE *BitF;

void WriteBitInit(FILE *F)
{
  BitF = F;
  accum = 0;
  pos = 7;
}

void WriteBit(int Bit)
{
  accum |= Bit << pos--;
  
  if (pos < 0)
  {
    pos = 7;
    fputc(accum, BitF);
    accum = 0;
  }
}

void WriteBitClose(void)
{
  if (pos != 7)
    fputc(accum, BitF);
}

void ReadBitInit(FILE *F)
{
  BitF = F;
  pos = -1;
}

int ReadBit(void)
{
  if (pos == -1)
  {
    accum = fgetc(BitF);
    pos = 7;
  }
  
  return (accum >> pos--) & 1;
}


