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
  double bmi[5];
  double maxBmi;

  //5人のデータ
  struct PERSON person[5] = {
    {"Alice", 155.0, 45.0},
    {"Bob", 170.0, 65.0},
    {"Carol", 163.0, 55.0},
    {"Dave", 180.0, 85.0},
    {"Ellen", 160.0, 56.0}
  };

  struct PERSON maxPerson;

  for (int i = 0; i < 5; i++)
  {
    bmi[i] = getBMI(person[i]);
  }

  maxBmi = bmi[0];
  for (int i = 0; i < 5; i++)
  {
    if (maxBmi < bmi[i])
    {
      maxBmi = bmi[i];
      maxPerson = person[i];
    }
  }

  for (int i = 0; i < 5; i++)
  {
    printf("%10s %5.1f %5.1f (%5.1f)\n", person[i].name, person[i].height, person[i].weight, bmi[i]);
  }
  printf("== MAX is\n");
  printf("%10s %5.1f %5.1f (%5.1f)\n", maxPerson.name, maxPerson.height, maxPerson.weight, maxBmi);
  return 0;
}
