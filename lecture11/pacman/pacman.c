/**
 * @file pacman.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdlib.h>
#include <handy.h>
#include <math.h>
#include "pacman.h"

#define PACMAN_STEP (1.0)
#define PAKUPAKU_SPEED (3)
#define RASIAN (M_PI / 4.0)
#define WINDOWSIZE (600.0)

/**
 * @brief 各種データをセットアップ
 *
 * @param x
 * @param y
 * @param size
 * @return PACMAN
 */
PACMAN pacman_Setup(float x, float y, float size, int change)
{
  PACMAN pacman;
  pacman.x = x;
  pacman.y = y;
  pacman.size = size;
  pacman.change = change;
  return pacman;
}

/**
 * @brief キー入力の処理を行う
 *
 * @param pacman_one
 * @return PACMAN
 */
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

/**
 * @brief player1について移動した後のpac変数を返す
 *
 * @param pacman_one
 * @return PACMAN
 */
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

/**
 * @brief パックマン左向き関数
 *
 * @param pacman_one
 * @param pakuCount
 * @param lid
 */
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

/**
 * @brief パックマン右向き関数
 *
 * @param pacman_one
 * @param pakuCount
 * @param lid
 */
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

/**
 * @brief パックマン上向き関数
 *
 * @param pacman_one
 * @param pakuCount
 * @param lid
 */
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

/**
 * @brief パックマン下向き関数
 *
 * @param pacman_one
 * @param pakuCount
 * @param lid
 */
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


