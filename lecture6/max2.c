#include <stdio.h>

int comparison(int i, int j)
{
  int n;

  if (i > j)
  {
    n = i;
  }
  else
  {
    n = j;
  }

  return n;
}

int main(void)
{
  int m, i, j, answer;

  scanf("%d", &i);
  scanf("%d", &j);

  answer = comparison(i, j);

  printf("answer = %d\n", answer);

  return 0;
}
