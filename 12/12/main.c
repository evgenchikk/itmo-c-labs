#include <stdio.h>
#include <time.h>

void GetStr( char *str, int max )
{
  int i = 0, ch;
  
  while ((ch = getchar()) != '\n')
    if (str != NULL && i < max - 1)
      str[i++] = ch;
  if (str != NULL && i < max)
    str[i] = 0;
}

int main( void )
{
  FILE *F;
  char filename[30];
  char str[10][10];
  time_t tim;
  struct tm *current_t;
  int i;
  
  tim = time(NULL);
  current_t = localtime(&tim);

  for (i = 0; i < 10; i++)
  {
    strftime(str[i], 10, "%d.%m.%y\n", current_t);
    current_t->tm_mday++;
    
    switch (current_t->tm_mon) {
      case 0: //jan 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 1: //feb 28
        if ((current_t->tm_mday) == 29)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 2: //mar 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 3: //apr 30
        if ((current_t->tm_mday) == 31)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 4: //may 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 5: //jun 30
        if ((current_t->tm_mday) == 31)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 6: //jul 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 7: //aug 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 8: //sep 30
        if ((current_t->tm_mday) == 31)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 9: //oct 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 10: //nov 30
        if ((current_t->tm_mday) == 31)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
        }
        break;
      case 11: //dec 31
        if ((current_t->tm_mday) == 32)
        {
          current_t->tm_mon++;
          current_t->tm_mday = 1;
          current_t->tm_year++;
        }
        break;
    }
  }
  
  printf("Input filename: ");
  GetStr(filename, 30);
  if ((F = fopen(filename, "wb")) == NULL)
    return 1;
  for (i = 0; i < 10; i++)
    fputs(str[i], F);
  fclose(F);
  
  return 0;
}
