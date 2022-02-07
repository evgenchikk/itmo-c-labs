#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huff.h"

int main(int argc, char *argv[])
{
    if (argc != 4 || !(strcmp(argv[1], "c") == 0 || strcmp(argv[1], "e") == 0))
    {
      printf("Info: \n %s {c|e} (Compress|Extract) Infile Outfile\n", argv[0]);
      return 1;
    }
  
    if (argv[1][0] == 'c')
      IncodeFile(argv[2], argv[3]);
    else
      DecodeFile(argv[2], argv[3]);
  
    return 0;
  
//  int flag = 1;
//  int ch;
//
//  while (flag)
//  {
//    Menu();
//
//    switch(ch = getchar())
//    {
//      case '0':
//        flag = 0;
//        break;
//      case '1':
//        IncodeFile("in.txt", "arhive.txt");
//        break;
//      case '2':
//        DecodeFile("arhive.txt", "out.txt");
//        break;
//    }
//  }
}

