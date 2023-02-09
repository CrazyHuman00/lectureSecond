#include <stdio.h>

int main()
{
  int firstnumber;
  int secondnumber;

  scanf("%d", &firstnumber);

  scanf("%d", &secondnumber);

  if (firstnumber == secondnumber)
  {
    printf("even\n");
  }

  if ((firstnumber == 1 && secondnumber == 2) || (firstnumber == 2 && secondnumber == 3) || (firstnumber == 3 && secondnumber == 1))
  {
    printf("win\n");
  }

  if ((firstnumber == 1 && secondnumber == 3) || (firstnumber == 2 && secondnumber == 1) || (firstnumber == 3 && secondnumber == 2))
  {
    printf("lose\n");
  }
  return 0;
}
