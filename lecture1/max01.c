#include<stdio.h>

int main()
{
  int num1, num2, num3, answer;


  printf("input number");
  scanf("%d",&num1);
  printf("input number");
  scanf("%d",&num2);
  printf("input number");
  scanf("%d",&num3);

  if(num1 > num2)
  {
    if(num3 > num1)
    {
      printf("answer : %d\n",num3);
    }else{
      printf("answer : %d\n",num1);
    }
  }
  else
  {
    if(num2 > num3)
    {
      printf("answer : %d\n",num2);
    }else{
      printf("answer : %d\n",num3);
    }
  }
  
  return 0;
}