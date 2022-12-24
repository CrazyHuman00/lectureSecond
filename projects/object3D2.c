//正八面体の3D

#include <stdio.h>
#include <handy.h>
#include <math.h>

#define WINDOWSIZE (800.0)  //中心座標(400, 400)
#define SLEEPTIME (0.01)
#define CENTER (WINDOWSIZE / 2.0)
#define LINELONG (400.0)


//座標データ
struct POSITION {
  float x, y, z;
};


int main(void)
{
  int window = HgOpen(WINDOWSIZE, WINDOWSIZE);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  const int vertex = 6;
  float s, c;
  float degree = 0.2;


  //座標指定
  struct POSITION p[vertex] = {
    1, 0, -1,   //0
    1, 0, 1,    //1
    -1, 0, 1,   //2
    -1, 0, -1,  //3
    0, 1, 0,    //4
    0, -1, 0,   //5
  };

  struct POSITION op[vertex];

  for (;;)
  {
    int layers = HgLSwitch(&dl);
    HgLClear(layers);

    s = sin(degree);
    c = cos(degree);
    degree += 0.01;

    for (int i = 0; i < vertex; i++)
    {
      op[i].x = p[i].x;
      op[i].y = p[i].y * c - p[i].z * s;
      op[i].z = p[i].y * s + p[i].z * c;

      op[i].x /= op[i].z + 4.0;
      op[i].y /= op[i].z + 4.0;
    }

    for (int i = 0; i < 4; i++)
    {
      int j = (i + 1) % 4;

      HgWSetWidth(layers, 3.0);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[j].x * LINELONG + CENTER, op[j].y * LINELONG + CENTER);

      //HgWLine(layers, op[4].x * LINELONG + CENTER, op[4].y * LINELONG + CENTER, op[5].x * LINELONG + CENTER, op[5].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[4].x * LINELONG + CENTER, op[4].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[5].x * LINELONG + CENTER, op[5].y * LINELONG + CENTER);
    }

    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
