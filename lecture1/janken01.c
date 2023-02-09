#include<stdio.h>

int main()
{
  int firstnumber, secondnumber;

  scanf("%d",&firstnumber);

  while(firstnumber > 3 || firstnumber < 1)
  {
    scanf("%d",&firstnumber);
  }
  
  scanf("%d",&secondnumber);

  while (secondnumber > 3 || secondnumber < 1)
  {
    scanf("%d",&secondnumber);
  }
  
  if(firstnumber == 1 && secondnumber == 1)
  {
    printf("even\n");
  }

  if(firstnumber == 2 && secondnumber == 2)
  {
    printf("even\n");
  }

  if(firstnumber == 3 && secondnumber == 3)
  {
    printf("even\n");
  }

  if(firstnumber == 1 && secondnumber == 2)
  {
    printf("win\n");
  }

  if(firstnumber == 2 && secondnumber == 3)
  {
    printf("win\n");
  }

  if(firstnumber == 3 && secondnumber == 1)
  {
    printf("win\n");
  }
  
  if(firstnumber == 1 && secondnumber == 3)
  {
    printf("lose\n");
  }

  if(firstnumber == 2 && secondnumber == 1)
  {
    printf("lose\n");
  }

  if(firstnumber == 3 && secondnumber == 1)
  {
    printf("lose\n");
  }

  return 0;

}