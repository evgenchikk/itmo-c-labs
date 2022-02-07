#include <stdio.h>

void StrCat( char *dest, char *src )
{
  while (*dest != 0)
    dest++;
  while ((*dest++ = *src++) != 0)
    ;
}

int StrCompare( char *str1, char *str2 )
{
  while ((*str1 == *str2) && (*str1 != 0))
  {
    str1++;
    str2++;
  }
  return *str1 - *str2;
}

void StrCopy( char *dest, char *src )
{
  while ((*dest++ = *src++) != 0)
    ;
}

int StrLength( char *str )
{
  int len = 0;
  
  while (*str++ != 0)
    len++;
  return len;
}

int StrSearch1( char *str, char c )
{
  int n = 0, res = 0;
  char *tmp = str;
  
  while (*str != 0)
  {
    if (*str++ == c)
      res = n;
    n++;
  }
  
  if (tmp[res] != c)
    return -1;
  return res;
}

int StrSearch2( char *str, char c )
{
  int len = StrLength(str);
  
  str = &str[len - 1];
  while ((len > 0) && (*str-- != c))
    len--;
  
  if (*(++str) != c)
    return -1;
  return len - 1;
}

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
  char str1[30], str2[30];
  
  printf("Input first string: ");
  GetStr(str1, 30);
  printf("Input second string: ");
  GetStr(str2, 30);
  
  StrCat(str1, str2);
  
  printf("%s\n", str1);
  
  //StrCopy(str1, str2);
  //printf("%s\n", str1);
  
  //printf("%i\n", StrLength(str1));
  
//  printf("%i\n", StrSearch2(str1, 'o'));
  
  return 0;
}
