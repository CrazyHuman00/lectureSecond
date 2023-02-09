#include<stdio.h>

int main()
{
  int total;
  int number;
  int count500,count100,count50,count10,count5,count1;
  int count[6] = {count500,count100,count50,count10,count5,count1};
  int price[6] = {500,100,50,10,5,1};
  
  scanf("%d",&total);

  for(number = 0;number <= 5;number++)
  {
    count[number] = total / price[number];
    total = total % price[number];
  }

  for(number = 0;number <= 5;number++)
  {
    printf("%d : %d\n",price[number],count[number]);
  }

  return 0;

}