#include <stdio.h>

int main(void)
{
  int max_number;
  int number, count, i_number;
  int data_1[5] = {};
  int data_2[5] = {};

  for (number = 0; number <= 4; number++)
  {
    scanf("%d", &data_1[number]);
  }

  // caluculate max number
  max_number = data_1[0];

  for (number = 0; number <= 4; number++)
  {
    if (max_number <= data_1[number])
    {
      max_number = data_1[number];
    }
  }

  for (number = 0; number <= 4; number++)
  {
    if (max_number == data_1[number])
    {
      count++;
    }
  }

  if(count == 5)
  {
    printf("data2 : all max\n");
    return 0;
  }

  printf("max : %d\n", max_number);


  // input dataes
  i_number = 0;

  for (number = 0; number <= 4; number++)
  {
    if (max_number != data_1[number])
    {
      data_2[4 - count - i_number] = data_1[number];
      i_number++;
    }
  }

  for (number = 0; number <= 4 - count; number++)
  {
    printf("data2[%d] : %d\n", number, data_2[number]);
  }

  return 0;
}