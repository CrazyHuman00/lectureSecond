#include <stdio.h>

int factorial(int firstNum, int secondNum)
{
  int count, numberF, numberS, sum;

  numberF = firstNum;
  for (count = firstNum - 1; count > 1; count--)
  {
    numberF *= count;
  }

  numberS = secondNum;
  for (count = secondNum - 1; count > 1; count--)
  {
    numberS *= count;
  }

  sum = numberF + numberS;

  return sum;
}


int main(void)
{
  int firstNum, secondNum, answer;

  scanf("%d", &firstNum);
  scanf("%d", &secondNum);

  answer = factorial(firstNum, secondNum);
  printf("%d\n", answer);

  return 0;
}

