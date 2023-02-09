#include <stdio.h>
#include <math.h>
#include <handy.h>

#define WINDOWSIZE (500)
#define FISHSIZE (50.0)
#define RASIAN (M_PI / 4.0)

//さかなー関数
void fish(double x, double y)
{
  double eyeCenterX = x + FISHSIZE / 3.0;
  double eyeCenterY = y + FISHSIZE / 2.0;
  double boneSize = (FISHSIZE * 2.0) / 6.0;
  int count;


  //魚の顔
  HgCircle(eyeCenterX, eyeCenterY, FISHSIZE / 4.0);
  HgFan(x, y, FISHSIZE, RASIAN * 5.0, RASIAN * 3.0);

  //魚の体
  for (count = 1; count <= 5; count++)
  {
    HgLine(x + FISHSIZE + boneSize * count, eyeCenterY, x + FISHSIZE + boneSize * count, eyeCenterY - FISHSIZE);
  }
  HgMoveTo(x + FISHSIZE, y);
  HgLineTo(x + FISHSIZE * 3.0, y);

  //魚の尻尾
  HgLineTo(x + FISHSIZE * 4.0, y + FISHSIZE);
  HgMoveTo(x + FISHSIZE * 3.0, y);
  HgLineTo(x + FISHSIZE * 4.0, y - FISHSIZE);

  return;
}

int main()
{
  HgOpen(WINDOWSIZE, WINDOWSIZE);

  double x, y;

  x = 150.0;
  y = 200.0;

  fish(x, y);

  HgGetChar();
  HgClose();
  return 0;
}
