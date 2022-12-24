//正二重面体の3D

#include <stdio.h>
#include <handy.h>
#include <math.h>

#define WINDOWSIZE (800.0) //中心座標(400, 400)
#define SLEEPTIME (0.01)
#define CENTER (WINDOWSIZE / 2.0)
#define LINELONG (400.0)

//座標データ
struct POSITION
{
  float x, y, z;
};

int main(void)
{
  int window = HgOpen(WINDOWSIZE, WINDOWSIZE);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  const int vertex = 12;
  float s, c;
  float degree = 0.2;
  float t = (1.0 + sqrt(5)) / 2.0;

  //座標指定
  struct POSITION p[vertex] = {
      -1, t, 0,  // 0
      1, t, 0,   // 1
      1, -t, 0,  // 2
      -1, -t, 0, // 3
      0, 1, t,   // 4
      0, -1, t,  // 5
      0, -1, -t, // 6
      0, 1, -t,  // 7
      -t, 0, 1,  // 8
      -t, 0, -1, // 9
      t, 0, -1,  // 10
      t, 0, 1,   // 11
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

    //描画を行う
    for (int i = 0; i < 4; i++)
    {
      int j = (i + 1) % 4;
      int h = i * 2;
      int a_number;
      int b_number;
      int c_number;
      int d_number;

      if (i == 1 || i == 2)
      {
        a_number = 10;
      }
      else
      {
        a_number = 8;
      }

      if (i == 1 || i == 0)
      {
        b_number = 7;
        c_number = 3;
      }
      else
      {
        b_number = 6;
        c_number = 1;
      }

      d_number = b_number - c_number;


      HgWSetWidth(layers, 3.0);

      //面を描く線
      HgWLine(layers, op[h].x * LINELONG + CENTER, op[h].y * LINELONG + CENTER, op[h + 1].x * LINELONG + CENTER, op[h + 1].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[a_number].x * LINELONG + CENTER, op[a_number].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[a_number + 1].x * LINELONG + CENTER, op[a_number + 1].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[b_number - c_number].x * LINELONG + CENTER, op[b_number - c_number].y * LINELONG + CENTER);

      HgWLine(layers, op[i].x * LINELONG + CENTER, op[i].y * LINELONG + CENTER, op[b_number].x * LINELONG + CENTER, op[b_number].y * LINELONG + CENTER);

      HgWLine(layers, op[b_number].x * LINELONG + CENTER, op[b_number].y * LINELONG + CENTER, op[10].x * LINELONG + CENTER, op[10].y * LINELONG + CENTER);

      HgWLine(layers, op[b_number].x * LINELONG + CENTER, op[b_number].y * LINELONG + CENTER, op[9].x * LINELONG + CENTER, op[9].y * LINELONG + CENTER);

      HgWLine(layers, op[d_number].x * LINELONG + CENTER, op[d_number].y * LINELONG + CENTER, op[8].x * LINELONG + CENTER, op[8].y * LINELONG + CENTER);

      HgWLine(layers, op[d_number].x * LINELONG + CENTER, op[d_number].y * LINELONG + CENTER, op[11].x * LINELONG + CENTER, op[11].y * LINELONG + CENTER);

    }

    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
