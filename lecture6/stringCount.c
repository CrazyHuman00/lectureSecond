#include <stdio.h>
#include <string.h>

int main(void)
{
  char textCount[100];

  int alphaCount = 0;
  int numCount = 0;
  int othersCount = 0;
  int length = 0;
  int number;

  scanf("%s", textCount);

  while (textCount[length] != '\0')
  {
    length++;
  }

  for (number = 0; number <= length; number++)
  {
    //アルファベットをカウント
    if (textCount[number] >= 'a' && textCount[number] <= 'z')
    {
      alphaCount++;
    }

    if (textCount[number] >= 'A' && textCount[number] <= 'Z')
    {
      alphaCount++;
    }


    //数字をカウント
    if (textCount[number] >= '0' && textCount[number] <= '9')
    {
      numCount++;
    }
  }

  othersCount = length - alphaCount - numCount;

  printf("Alpha = %d Number = %d Else = %d\n", alphaCount, numCount, othersCount);

  return 0;
}
