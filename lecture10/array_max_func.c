#include <stdio.h>
#include <math.h>

#define COUNT (5)

int sortFanc(int array[COUNT])
{
  int a = array[0];
  for (int i = 0; i < COUNT; i++)
  {
    if (a <= array[i])
    {
      a = array[i];
    }
  }

  return a;
}

int main(void)
{
  int number;
  int array[COUNT];

  for (int i = 0; i < COUNT; i ++)
  {
    scanf("%d", &array[i]);
  }

  int a = sortFanc(array);
  printf("max : %d\n", a);

  return 0;

}
