#include <stdio.h>

int main(void)
{
  int i_number, j_number, tmp_count;
  int hundred_array[100] = {};

  for (i_number = 0; i_number < 5; i_number++)
  {
    scanf("%d", &hundred_array[i_number]);
  }

  for (i_number = 0; i_number < 5; i_number++)
  {
    for (j_number = i_number + 1; j_number < 5; j_number++)
    {
      if (hundred_array[i_number] > hundred_array[j_number])
      {
        tmp_count = hundred_array[i_number];
        hundred_array[i_number] = hundred_array[j_number];
        hundred_array[j_number] = tmp_count;
      }
    }
  }

  for(i_number = 0; i_number < 5; i_number++)
  {
    printf("%d ", hundred_array[i_number]);
  }

  printf("\n");

  return 0;
}