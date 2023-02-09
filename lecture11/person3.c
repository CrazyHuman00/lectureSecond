#include <stdio.h>
#include <handy.h>
#include <math.h>

//人間データ
typedef struct PERSON
{
  char name[32];  //名前
  double height;  //身長
  double weight;  //体重
} PERSON;

//BMI関数
double getBMI(PERSON p)
{
  double meter_of_height = p.height / 100.0;
  double Bmi = p.weight / (meter_of_height * meter_of_height);
  return Bmi;
}

int main(void)
{
  PERSON bob = {"bob", 170.0, 65.0};
  double bmi = getBMI(bob);
  printf("%10s %5.1f %5.1f (%5.1f)\n", bob.name, bob.height, bob.weight, bmi);
  return 0;
}
