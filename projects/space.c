// 253037
// Asakura Hiroto
//
// 宇宙の3Dゲームを制作した。流れてくる緑コアを回収してスコアを稼ごう。
// しかし赤コアに衝突するとライフが削れる。
//
//

#include <stdio.h>
#include <handy.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WINDOWSIZE_W (1000.0)
#define WINDOWSIZE_H (700.0)
#define CENTER_X (WINDOWSIZE_W / 2.0)
#define CENTER_Y (WINDOWSIZE_H / 2.0)
#define SLEEPTIME (1.0 / 60.0)

// 座標データ
struct POSITION_STAR
{
  float x, y, z;
};

struct POSITION_CUBE
{
  float x, y, z;
};

// 最大値最小値を指定してその範囲で乱数生成をする関数
float get_random_in_range(float min, float max) {
  return ((float) rand() / RAND_MAX) * (max - min) + min;
}

//void drawing_cube()
//{
//
//}

int main(void)
{
  int window = HgOpen(WINDOWSIZE_W, WINDOWSIZE_H);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  // 背景を黒く染める
  HgSetFillColor(HG_BLACK);
  HgBoxFill(0, 0, WINDOWSIZE_W, WINDOWSIZE_H, 0);

  //半透明色の生成
  int clear_color = HgRGBA(1.0, 1.0, 1.0, 0.01);

  const int starcip = 100;
  const int vertex = 8;
  struct POSITION_STAR p[starcip];


  //現在初期化して乱数を表示
  srandom(time(NULL));
  for (int i = 0; i < starcip; i++)
  {
    p[i].x = get_random_in_range(-1.0, 1.0);  //-1.0~1.0
    p[i].y = get_random_in_range(-0.5, 0.5);  //-0.5~0.5
    p[i].z = get_random_in_range(0.0, 1.0);   //0.0~1.0
  }


  //アニメーション
  for (;;)
  {
    int layers = HgLSwitch(&dl);
    HgLClear(layers);

    for (int i = 0; i < starcip; i++)
    {
      p[i].z -= 0.008;
      if (p[i].z <= 0.0)
      {
        p[i].z = 1.0;
      }
    }

    for (int i = 0; i < starcip; i++)
    {
      float size = (1.0 - p[i].z) * 5.0;

      HgWSetFillColor(layers, HG_WHITE);
      HgWCircleFill(layers, p[i].x / p[i].z * CENTER_X + CENTER_X, p[i].y / p[i].z * CENTER_Y + CENTER_Y, size, 0);
    }


    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
