#include<stdio.h>

int main()
{
  int num1, num2;

  printf("input number");
  scanf("%d",&num1);
  printf("input number");
  scanf("%d",&num2);

  if(num1 >= num2)
  {
    printf("answer : %d\n",num1);
  }else{
    printf("answer : %d\n",num2);
  }

  return 0;

}