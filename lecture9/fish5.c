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
  HgWCircleFill(lid, eyeCenterXL, eyeCenterYL, fishSize / 4.0, 0);

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
  int window = HgOpen(WINDOWSIZE, WINDOWSIZE);

  doubleLayer layers;
  layers = HgWAddDoubleLayer(0);

  int i;
  int num = 10; //魚の数

  float x, y, dx, dy, size;
  float s, t, ds, dt, kingsize;
  float dxAdd[num];    //x軸方向の速度
  float dyAdd[num];    //y軸方向の速度
  float xstart[num];   //xの初期地点
  float ystart[num];   //yの初期地点
  float fishSize[num]; //魚のサイズ

  srandom(time(NULL));
  for (i = 0; i < num; i++)
  {
    xstart[i] = random() % 400;
    ystart[i] = random() % 400;
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

    //キングフィッシュの座標、速度設定
    s = xstart[0];
    t = ystart[0];
    kingsize = fishSize[0];
    ds = dxAdd[0];
    dt = dyAdd[0];


    // dsが0以上なら右向き
    if (ds > 0)
    {
      fishRight(s, t, kingsize, win);
      HgWSetColor(win, HG_RED);
      HgWCircle(win, s + kingsize * 3, t, kingsize + 10);
    }
    else
    {
      fishLeft(s, t, kingsize, win);
      HgWSetColor(win, HG_RED);
      HgWCircle(win, s, t, kingsize + 10);
    }

    if ((t < kingsize && dt < 0) || (t > (WINDOWSIZE - kingsize) && dt > 0))
    {
      dyAdd[0] = -dt;
    }

    if ((s < kingsize && ds < 0) || (s > (WINDOWSIZE - kingsize * 4.0) && ds > 0))
    {
      dxAdd[0] = -ds;
    }

    for (i = 1; i < num; i++)
    {
      x = xstart[i];
      y = ystart[i];
      size = fishSize[i];
      dx = dxAdd[i];
      dy = dyAdd[i];

      //距離を測る変数
      float k = x + size * 3.0;
      float h = s + kingsize * 3.0;
      float distanceA = (x - h) * (x - h) + (y - t) * (y - t);
      float distanceB = (k - s) * (k - s) + (y - t) * (y - t);

      // dxが0以上なら右向き
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

      //キングフィッシュに近づけば移動方向を変える
      if (distanceA <= (kingsize + 10) * (kingsize + 10) || distanceB <= (kingsize + 10) * (kingsize + 10))
      {
        dxAdd[i] = dxAdd[0];
        dyAdd[i] = dyAdd[0];
      }


      ystart[i] += dyAdd[i];
      xstart[i] += dxAdd[i];
    }

    ystart[0] += dyAdd[0];
    xstart[0] += dxAdd[0];

    HgSleep(0.1);
  }

  HgGetChar();
  HgClose();
  return 0;
}
