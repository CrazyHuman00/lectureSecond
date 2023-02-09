#include <stdio.h>
#include <math.h>
#include <handy.h>

#define WINDOWSIZE (500)
#define fishSize (30.0)
#define RASIAN (M_PI / 4.0)


//さかなー左向き関数
void fishLeft(double x, double y, int lid)
{

  double eyeCenterXL = x + fishSize / 3.0;
  double eyeCenterYL = y + fishSize / 2.0;
  double boneSize = (fishSize * 2.0) / 6.0;
  int count;

  //魚の顔
  HgWSetFillColor(lid, HG_BLUE);
  HgWFanFill(lid, x, y, fishSize, RASIAN * 5.0, RASIAN * 3.0, 0);
  HgWSetFillColor(lid, HG_WHITE);
  HgWCircleFill(lid,eyeCenterXL, eyeCenterYL, fishSize / 4.0, 0);

  //魚の体
  HgWSetColor(lid, HG_BLUE);
  for (count = 1; count <= 5; count++)
  {
    HgWLine(lid, x + fishSize + boneSize * count, eyeCenterYL, x + fishSize + boneSize * count, eyeCenterYL - fishSize);
  }
  HgWMoveTo(lid, x + fishSize, y);
  HgWLineTo(lid, x + fishSize * 3.0, y);

  //魚の尻尾
  HgWLineTo(lid, x + fishSize * 4.0, y + fishSize);
  HgWMoveTo(lid, x + fishSize * 3.0, y);
  HgWLineTo(lid, x + fishSize * 4.0, y - fishSize);
}

//さかなー右向き関数
void fishRight(double x, double y, int lid)
{

  double s = x + fishSize * 3.0;
  double eyeCenterXR = s - fishSize / 3.0;
  double eyeCenterYR = y + fishSize / 2.0;
  double boneSize = (fishSize * 2.0) / 6.0;
  int count;

  //魚の顔
  HgWSetFillColor(lid, HG_BLUE);
  HgWFanFill(lid, s, y, fishSize, RASIAN, RASIAN * 7.0, 0);
  HgWSetFillColor(lid, HG_WHITE);
  HgWCircleFill(lid, eyeCenterXR, eyeCenterYR, fishSize / 4.0, 0);

  //魚の体
  HgWSetColor(lid, HG_BLUE);
  for (count = 1; count <= 5; count++)
  {
    HgWLine(lid, s - fishSize - (boneSize * count), eyeCenterYR, s - fishSize - boneSize * count, eyeCenterYR - fishSize);
  }
  HgWMoveTo(lid, s - fishSize, y);
  HgWLineTo(lid, s - fishSize * 3.0, y);

  //魚の尻尾
  HgWLineTo(lid, s - fishSize * 4.0, y + fishSize);
  HgWMoveTo(lid, s - fishSize * 3.0, y);
  HgWLineTo(lid, s - fishSize * 4.0, y - fishSize);
}


int main(void)
{
  HgOpen(WINDOWSIZE, WINDOWSIZE);

  doubleLayer layers;
  layers = HgWAddDoubleLayer(0);

  double x, y, dx, dy;
  int dirction = 0;

  x = 150.0;
  y = 200.0;
  dx = -10.0;
  dy = 5.0;


  //アニメーション
  for (;;)
  {
    int win = HgLSwitch(&layers);
    HgLClear(win);

    if (x - fishSize < 0)
    {
      dx *= -1.0;
      dirction = 1;
    }

    if (x + fishSize * 4 > WINDOWSIZE)
    {
      dx *= -1.0;
      dirction = 0;
    }

    if (y + fishSize > WINDOWSIZE || y - fishSize < 0)
    {
      dy *= -1.0;
    }

    if (dirction == 0)
    {
      fishLeft(x, y, win);
    }

    if (dirction == 1)
    {
      fishRight(x, y, win);
    }
    x += dx;
    y += dy;

    HgSleep(0.1);
  }

  HgGetChar();
  HgClose();
  return 0;
}
