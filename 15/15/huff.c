#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "huff.h"
#include "bitrw.h"

typedef struct tagTREE TREE;
struct tagTREE
{
  char ch;
  long Freq;
  TREE *Left, *Right;
};

typedef struct
{
  int Code[47], len;
} CODE;

long Freq[256];
TREE *Nodes[256];
int NumOfNodes = 0;


void CountFreq(FILE *F)
{
  int i;
  
  memset(Freq, 0, sizeof(Freq));
  while ((i = fgetc(F)) != EOF)
    Freq[i]++;
  
  //  for (i = 0; i < 256; i++)
  //    if (Freq[i] > 0)
  //      printf("%c (%d) - %d\n", i, i, Freq[i]);
}

void PlaceNode(char ch, long Freq, TREE *L, TREE *R)
{
  TREE *T;
  int i;
  
  if ((T = malloc(sizeof(TREE))) == NULL)
    return;
  
  T->ch = ch;
  T->Freq = Freq;
  T->Left = L;
  T->Right = R;
  
  i = NumOfNodes - 1;
  
  while (i >= 0 && T->Freq > Nodes[i]->Freq)
  {
    Nodes[i + 1] = Nodes[i];
    i--;
  }
  
  Nodes[i + 1] = T;
  NumOfNodes++;
}

//a - 28
//b - 33
//c - 40
//d - 30
//[c - 40]n=1 [b - 33]n=2 [d - 30]n=3 [a - 28]n=4

void DrawTree(TREE *T, int Level)
{
  if (T != NULL)
  {
    DrawTree(T->Right, Level + 1);
    //    printf("%*c%i\n", Level * 3, ' ', T->Freq);
    DrawTree(T->Left, Level + 1);
  }
}

CODE NewCodes[256], CurCode;

void BuildCodes(TREE *T)
{
  CurCode.Code[CurCode.len] = 0;
  CurCode.len++;
  if (T->Left != NULL)
    BuildCodes(T->Left);
  CurCode.len--;
  
  CurCode.Code[CurCode.len] = 1;
  CurCode.len++;
  if (T->Right != NULL)
    BuildCodes(T->Right);
  CurCode.len--;
  
  if (T->Left == NULL || T->Right == NULL)
    NewCodes[(unsigned char)T->ch] = CurCode;
}

void BuildTree(void)
{
  TREE *Last, *PreLast;
  
  while (NumOfNodes != 1)
  {
    Last = Nodes[--NumOfNodes];
    PreLast = Nodes[--NumOfNodes];
    PlaceNode(' ', Last->Freq + PreLast->Freq, PreLast, Last);
  }
  
  //  printf("\n");
  //  DrawTree(Nodes[0], 0);
}

void IncodeFile(char *InF, char *OutF)
{
  FILE *Fin, *Fout;
  int i;
  int ch;
  
  Fin = fopen(InF, "r");
  Fout = fopen(OutF, "wb");
  
  printf("\n");
  
  CountFreq(Fin);
  
  for (i = 0; i < 256; i++)
    if (Freq[i] > 0)
      PlaceNode(i, Freq[i], NULL, NULL);
  
  //  printf("\n");
  //
  //  for (i = 0; i < NumOfNodes; i++)
  //    printf("%l ", Nodes[i]->Freq);
  //
  //  printf("\n");
  
  BuildTree();
  
  CurCode.len = 0;
  BuildCodes(Nodes[0]);
  
  //  for (i = 0; i < 256; i++)
  //    if (Freq[i] > 0)
  //    {
  //      printf("%c - ", i);
  //
  //      for (j = 0; j < NewCodes[i].len; j++)
  //        printf("%d", NewCodes[i].Code[j]);
  //
  //      printf("\n");
  //    }
  
  WriteBitInit(Fout);
  
  fwrite(Freq, sizeof(long), 256, Fout);
  rewind(Fin);
  while((ch = fgetc(Fin)) != EOF)
    for (i = 0; i < NewCodes[ch].len; i++)
      WriteBit(NewCodes[ch].Code[i]);
  
  WriteBitClose();
  
  fclose(Fin);
  fclose(Fout);
}

void DecodeFile(char *InF, char *OutF)
{
  TREE *T;
  FILE *Fin, *Fout;
  long i, amm;
  
  Fin = fopen(InF, "rb");
  Fout = fopen(OutF, "w");
  
  printf("\n");
  
  ReadBitInit(Fin);
  
  fread(Freq, sizeof(long), 256, Fin);
  
  NumOfNodes = 0;
  
  for (i = 0; i < 256; i++)
    if (Freq[i] > 0)
      PlaceNode(i, Freq[i], NULL, NULL);
  
  //  for (i = 0; i < NumOfNodes; i++)
  //    printf("%i ", Nodes[i]->Freq);
  
  BuildTree();
  
  T = Nodes[0];
  amm = T->Freq;
  i = 0;
  
  while(i < amm)
  {
    if (ReadBit() == 0)
      T = T->Left;
    else
      T = T->Right;
    
    if ((T->Right == NULL) || (T->Left == NULL))
    {
      fprintf(Fout, "%c", (unsigned char)T->ch);
      T = Nodes[0];
      i++;
    }
  }
  
  fclose(Fin);
  fclose(Fout);
}

void Menu(void)
{
  printf("0 - Exit\n"
         "1 - Incode file\n"
         "2 - Decode file\n");
}

void GetStr(char *Str, int MaxLen)
{
  int i = 0;
  char c;
  while ((c = getchar()) != '\n')
    if (Str != NULL && i < MaxLen)
      Str[i++] = c;
  if (Str != NULL)
    Str[i] = 0;
}

