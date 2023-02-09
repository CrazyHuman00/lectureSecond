#include <stdio.h>

int factorialF(int n)
{
  int i, f;

  f = n;
  for (i = n - 1; i > 1; i--)
  {
    f *= i;
  }

  return f;
}

int factorialS(int m)
{
  int j, k;

  k = m;
  for (j = m - 1; j > 1; j--)
  {
    k *= j;
  }

  return k;
}

int main(void)
{
  int n, m, sum, fancF, fancS;

  scanf("%d", &n);
  scanf("%d", &m);

  fancF = factorialF(n);
  fancS = factorialS(m);

  sum = fancF + fancS;

  printf("sum = %d\n", sum);

  return 0;
}
