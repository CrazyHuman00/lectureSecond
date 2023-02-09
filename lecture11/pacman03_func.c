/**
 * @file pacman03_func.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-11
 *
 * @copyright Copyright (c) 2023
 *
 *
 */

#include <stdio.h>
#include <handy.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WINDOWSIZE (600)
#define RASIAN (M_PI / 4.0)
#define SLEEPTIME (0.01)
#define PACMAN_STEP (1.0)
#define PAKUPAKU_SPEED (3)

// パックマンデータ
typedef struct PACMAN
{
  float x, y;
  float size;
  float dx, dy;
  int paku;
} PACMAN;

// 各種データをセットアップ
PACMAN pacman_Setup(float x, float y, float size)
{
  PACMAN pacman;
  pacman.x = x;
  pacman.y = y;
  pacman.size = size;
  return pacman;
}


// player1のキー入力の処理を行う
PACMAN pacman_KeyIn_one(PACMAN pacman_one)
{
  HgSetEventMask(HG_KEY_DOWN);
  hgevent *event = HgEventNonBlocking();

  if (event != NULL)
  {
    if (event->type == HG_KEY_DOWN)
    {
      switch (event->ch)
      {
      case 'i':
        pacman_one.dx = 0.0;
        pacman_one.dy = PACMAN_STEP;
        break;

      case 'k':
        pacman_one.dx = 0.0;
        pacman_one.dy = -PACMAN_STEP;
        break;

      case 'j':
        pacman_one.dx = -PACMAN_STEP;
        pacman_one.dy = 0.0;
        break;

      case 'l':
        pacman_one.dx = PACMAN_STEP;
        pacman_one.dy = 0.0;
        break;
      }
    }
  }

  return pacman_one;
}


// player1について移動した後のpac変数を返す
PACMAN pacman_Move_one(PACMAN pacman_one)
{
  pacman_one.x += pacman_one.dx;
  pacman_one.y += pacman_one.dy;
  pacman_one.paku += 1;
  if (pacman_one.paku >= 100)
  {
    pacman_one.paku = 1;
  }
  return pacman_one;
}


// パックマン左向き関数
void pacman_left(PACMAN pacman_one, int pakuCount, int lid)
{
  float x = pacman_one.x;
  float y = pacman_one.y;
  float size = pacman_one.size;
  float eyeCenterXL = x + size / 3.0;
  float eyeCenterYL = y + size / 2.0;

  HgWSetFillColor(lid, HG_YELLOW);
  if ((pakuCount % PAKUPAKU_SPEED) == 0)
  {
    HgWFanFill(lid, x, y, size, RASIAN * 5.0, RASIAN * 3.0, 0);
  }
  else
  {
    HgWFanFill(lid, x, y, size, RASIAN * 4.1, RASIAN * 3.9, 0);
  }
  HgWSetFillColor(lid, HG_DBLUE);
  HgWCircleFill(lid, eyeCenterXL, eyeCenterYL, size / 4.0, 0);
}

// パックマン右向き関数
void pacman_right(PACMAN pacman_one, int pakuCount, int lid)
{
  float x = pacman_one.x;
  float y = pacman_one.y;
  float size = pacman_one.size;
  float eyeCenterXR = x - size / 3.0;
  float eyeCenterYR = y + size / 2.0;

  HgWSetFillColor(lid, HG_YELLOW);
  if ((pakuCount % PAKUPAKU_SPEED) == 0)
  {
    HgWFanFill(lid, x, y, size, RASIAN, RASIAN * 7.0, 0);
  }
  else
  {
    HgWFanFill(lid, x, y, size, RASIAN * 0.1, RASIAN * 7.9, 0);
  }
  HgWSetFillColor(lid, HG_DBLUE);
  HgWCircleFill(lid, eyeCenterXR, eyeCenterYR, size / 4.0, 0);
}

// パックマン上向き関数
void pacman_up(PACMAN pacman_one, int pakuCount, int lid)
{
  float x = pacman_one.x;
  float y = pacman_one.y;
  float size = pacman_one.size;
  float eyeCenterXU = x - size / 3.0;
  float eyeCenterYU = y - size / 2.0;

  HgWSetFillColor(lid, HG_YELLOW);
  if ((pakuCount % PAKUPAKU_SPEED) == 0)
  {
    HgWFanFill(lid, x, y, size, RASIAN * 3.0, RASIAN, 0);
  }
  else
  {
    HgWFanFill(lid, x, y, size, RASIAN * 2.1, RASIAN * 1.9, 0);
  }
  HgWSetFillColor(lid, HG_DBLUE);
  HgWCircleFill(lid, eyeCenterXU, eyeCenterYU, size / 4.0, 0);
}

// パックマン下向き関数
void pacman_down(PACMAN pacman_one, int pakuCount, int lid)
{
  float x = pacman_one.x;
  float y = pacman_one.y;
  float size = pacman_one.size;
  float eyeCenterXD = x + size / 3.0;
  float eyeCenterYD = y + size / 2.0;

  HgWSetFillColor(lid, HG_YELLOW);
  if ((pakuCount % PAKUPAKU_SPEED) == 0)
  {
    HgWFanFill(lid, x, y, size, RASIAN * 7.0, RASIAN * 5.0, 0);
  }
  else
  {
    HgWFanFill(lid, x, y, size, RASIAN * 6.1, RASIAN * 5.9, 0);
  }
  HgWSetFillColor(lid, HG_DBLUE);
  HgWCircleFill(lid, eyeCenterXD, eyeCenterYD, size / 4.0, 0);
}

// メイン関数
int main(void)
{
  int window = HgOpen(WINDOWSIZE, WINDOWSIZE);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  int pakuCountOne = 0;

  // 背景を藍色に染める
  HgSetFillColor(HG_DBLUE);
  HgBoxFill(0, 0, WINDOWSIZE, WINDOWSIZE, 0);

  PACMAN pacman_one;

  // パックマンのセットアップを行う
  pacman_one = pacman_Setup(40.0, 40.0, 20.0);

  // アニメーション
  for (;;)
  {
    int layers = HgLSwitch(&dl);
    HgLClear(layers);

    pakuCountOne = pacman_one.paku;

    pacman_one = pacman_KeyIn_one(pacman_one);  // player1のキー入力処理
    pacman_one = pacman_Move_one(pacman_one);   // player1の移動処理

    // player1の向き判定と当たり判定
    if (pacman_one.dx < 0.0 && pacman_one.dy == 0.0)
    {
      pacman_left(pacman_one, pakuCountOne, layers); // 左
    }
    else if (pacman_one.dx > 0.0 && pacman_one.dy == 0.0)
    {
      pacman_right(pacman_one, pakuCountOne, layers); // 右
    }
    else if (pacman_one.dy < 0.0 && pacman_one.dx == 0.0)
    {
      pacman_down(pacman_one, pakuCountOne, layers); // 下
    }
    else if (pacman_one.dy > 0.0 && pacman_one.dx == 0.0)
    {
      pacman_up(pacman_one, pakuCountOne, layers); // 上
    }

    if (pacman_one.y < pacman_one.size || pacman_one.y > (WINDOWSIZE - pacman_one.size))
    {
      pacman_one.dy *= -1.0;
    }

    if (pacman_one.x < pacman_one.size || pacman_one.x > (WINDOWSIZE - pacman_one.size))
    {
      pacman_one.dx *= -1.0;
    }


    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
