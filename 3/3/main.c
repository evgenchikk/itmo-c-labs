#include <stdio.h>

//#include <math.h>
//int check( int x )
//{
//  do
//    if (x % 10 > 7)
//      return 0;
//    else
//      x /= 10;
//  while (x != 0);
//
//  return 1;
//}
//
//int translate8to10( int x )
//{
//  int res = 0, i = 0;
//
//  do
//  {
//    res += (x % 10) * pow(8, i++);
//    x /= 10;
//  }
//  while (x != 0);
//
//  return res;
//}
//
//int translate10to8( int x )
//{
//  int res = 0, i = 0;
//
//  while (x != 0)
//  {
//    res += (x % 8) * pow(10, i++);
//    x /= 8;
//  }
//
//  return res;
//}
//
//int main( void )
//{
//  int x, a, y, b;
//
//  printf("Input number in octal number system: "); //Task 1
//  scanf("%i", &x);
//  if (check(x) == 0)
//  {
//    printf("Wrong number!\n");
//    return 1;
//  }
//  a = translate8to10(x);
//  printf("Your number in decimal number systmes: %i\n", a); //Task 2
//  printf("Shift 1 bit left: %i\n", translate10to8(a << 1)); //Task 3
//  printf("Bit negative operation: %i\n", translate10to8(~a)); //Task 4
//  printf("Input number in octal number system: ");
//  scanf("%i", &y);
//  if (check(y) == 0)
//  {
//    printf("Wrong number!\n");
//    return 1;
//  }
//  b = translate8to10(y);
//  printf("%i & %i = %i", x, y, translate10to8(a & b)); //Task 5
//  return 0;
//}

int main(void)
{
  int octal, octal2;
  
  printf("Task 1:\n");
  printf("Input octal number: "); //Task 1
  scanf("%o", &octal);
  
  printf("\nTask 2:\n");
  printf("Number in decimal: %d\n\n", octal); //Task 2
  
  printf("Task 3:\n");
  printf("Number in octal: %o\n", octal);
  printf("Bit shift left: %o\n\n", octal << 1); //Task 3
  
//  17 -          001 111
//  сдвиг << 1    011 110 (36)
  
  printf("Task 4:\n");
  printf("Number in octal: %o\n", octal);
  printf("Bit negative: %o\n\n", ~octal); //Task 4

//  17 -          0000 0000 0000 0000 0000 0000 0000 1111 (32 бит)
//  отрицание     1111 1111 1111 1111 1111 1111 1111 0000 (37777777760)
  
  printf("Task 5:\n");
  printf("Input octal number: ");
  scanf("%o", &octal2);
  printf("\nBit 'and': %o\n", octal & octal2); //Task 5
  
//  17 - 001 111
//  24 - 010 100
//  &  - 000 100 - (4)
  
  return 0;
}
