#include <stdio.h>

double func(double x)
{
  return 1 / x;
}

int main(void)
{
  double a = 4.0; /* 区間 [a,b] */
  double b = 7.0;
  int n = 3;                       /* 区間を 2n 等分する */
  double s = 0.0;                  /* 関数の和 */
  for (int i = 0; i <= 2 * n; ++i) /* 2n 等分の i 番目 (0 ≦ i ≦ 2n) */
  {
    double ai = a + (b - a) * i / (2 * n); /* 分点 */

    if (i == 0 || i == 2 * n)
    { /* 左端・右端のとき */
      s += func(ai);
    }
    else if (i % 2 == 0)
    { /* 途中の偶数番のとき */
      s += 2 * func(ai);
    }
    else
    { /* 奇数番のとき */
      s += 4 * func(ai);
    }
  }
  double value = s * (b - a) / (6 * n); /* 積分の近似値 */
  printf("[a,b]=[%f,%f], n=%d, value=%f\n", a, b, n, value);
  return 0;
}

