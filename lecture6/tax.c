#include <stdio.h>

double taxRate(double price, double tax)
{
  double cost;

  cost = price * tax;

  return cost;
}

int main(void)
{
  double price, pay, tax;

  printf("単価 = ");
  scanf("%lf", &price);
  printf("消費税率 = ");
  scanf("%lf", &tax);

  pay = taxRate(price, tax);

  printf("価格 = %f\n", pay);

  return 0;
}
