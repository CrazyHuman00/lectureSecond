#include <stdio.h>
#include <math.h>
#include <handy.h>
#include <time.h>
#include <stdlib.h>

#define WINDOWSIZE (500)
#define RASIAN (M_PI / 4.0)

//さかなー左向き関数
void fishLeft(float x, float y, float fishSize, int lid)
{

  float eyeCenterXL = x + fishSize / 3.0;
  float eyeCenterYL = y + fishSize / 2.0;
  float boneSize = (fishSize * 2.0) / 6.0;
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
void fishRight(float x, float y, float fishSize, int lid)
{

  float s = x + fishSize * 3.0;
  float eyeCenterXR = s - fishSize / 3.0;
  float eyeCenterYR = y + fishSize / 2.0;
  float boneSize = (fishSize * 2.0) / 6.0;
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

  int i;
  int num = 10;  //魚の数

  float x, y, dx, dy, size;
  float dxAdd[num];  //x軸方向の速度
  float dyAdd[num];  //y軸方向の速度
  float xstart[num];  //xの初期地点
  float ystart[num];  //yの初期地点
  float fishSize[num];  //魚のサイズ


  srandom(time(NULL));
  for (i = 0; i < num; i++)
  {
    xstart[i] = random() % 400;
    ystart[i] = WINDOWSIZE + 50;
    fishSize[i] = random() % 30 + 10;
    dxAdd[i] = random() % 20 - 10;
    dyAdd[i] = random() % 20 - 10;

    if (dxAdd[i] == 0)
    {
      dxAdd[i] = 10.0;
    }

    if (dyAdd[i] == 0)
    {
      dyAdd[i] = 10.0;
    }
  }


  //アニメーション
  for (;;)
  {
    int win = HgLSwitch(&layers);
    HgLClear(win);

    for (i = 0; i < num; i++)
    {
      x = xstart[i];
      y = ystart[i];
      size = fishSize[i];
      dx = dxAdd[i];
      dy = dyAdd[i];

      //dxが0以上なら右向き
      if (dx > 0)
      {
        fishRight(x, y, size, win);
      }
      else
      {
        fishLeft(x, y, size, win);
      }

      if ((y < size && dy < 0) || (y > (WINDOWSIZE - size) && dy > 0))
      {
        dyAdd[i] = -dy;
      }

      if ((x < size && dx < 0) || (x > (WINDOWSIZE - size * 4.0) && dx > 0))
      {
        dxAdd[i] = -dx;
      }

      ystart[i] += dyAdd[i];
      xstart[i] += dxAdd[i];
    }

    HgSleep(0.1);
  }

  HgGetChar();
  HgClose();
  return 0;
}
