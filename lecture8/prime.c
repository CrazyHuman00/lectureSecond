#include <stdio.h>

int primeFanc(int i)
{
  int count;
  int flag = 0;

  for (count = 2; count < i; count++)
  {
    if (i % count == 0)
    {
      flag = 1;
      break;
    }
  }

  return flag;
}

int main(void)
{
  int a;

  scanf("%d", &a);

  primeFanc(a);

  if (primeFanc(a) == 1)
  {
    printf("not prime\n");
  }
  else
  {
    printf("prime\n");
  }

  return 0;
}
