#include <stdio.h>

int leapyearFanc(int a)
{
  int b;

  if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0))
  {
    b = 1;
  }
  else
  {
    b = 0;
  }

  return b;
}

int main(void)
{
  int year;

  scanf("%d", &year);

  leapyearFanc(year);

  if (leapyearFanc(year) == 1)
  {
    printf("leap\n");
  }
  else
  {
    printf("not laep\n");
  }

  return 0;
}
