#include <stdio.h>

int main(void)
{
  int number, count;
  int primeflag;

  for (number = 2; number <= 100; number++)
  {

    primeflag = 0;

    for (count = 2; count < number; count++)
    {
      if (number % count == 0)
      {
        primeflag = 1;
        break;
      }
    }

    if (primeflag == 0)
    {
      printf("%d is prime\n", number);
    }

    if (primeflag == 1)
    {
      printf("%d is not prime\n", number);
    }
  }
  return 0;
}