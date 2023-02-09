#include <stdio.h>

int comparison(int firstNum, int secondNum, int thirdNum)
{
  int n = firstNum;

  if (n < secondNum)
  {
    n = secondNum;
    if (n < thirdNum)
    {
      n = thirdNum;
    }
  }

  if (n < thirdNum)
  {
    n = thirdNum;
    if (n < secondNum)
    {
      n = secondNum;
    }
  }

  return n;
}


int main(void)
{
  int firstNum, secondNum, thirdNum;
  int answer;

  scanf("%d", &firstNum);
  scanf("%d", &secondNum);
  scanf("%d", &thirdNum);

  answer = comparison(firstNum, secondNum, thirdNum);

  printf("answer = %d\n", answer);

  return 0;
}

