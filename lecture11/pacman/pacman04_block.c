/**
 * @file pacman04_block.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-12
 *
 * @copyright Copyright (c) 2023
 *
 * パックマンの制作課題。
 * i ↑
 * k ↓
 * l →
 * j ←
 * の方向に進む。
 * 線を四角形として考える
 */

#include <stdio.h>
#include <handy.h>
#include <stdlib.h>
#include "field.h"
#include "pacman.h"
#include "hit.h"
#include "object.h"

#define WINDOWSIZE (600.0)
#define SLEEPTIME (0.01)
#define PAKUPAKU_SPEED (3)
#define PACMAN_STEP (1.0)
#define RASIAN (M_PI / 4.0)


/**
 * @brief main
 *
 * @return int
 */
int main(void)
{
  int window = HgOpen(WINDOWSIZE, WINDOWSIZE);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  int pakuCountOne = 0; // パクパクカウント

  // 背景を藍色に染める
  HgSetFillColor(HG_DBLUE);
  HgBoxFill(0, 0, WINDOWSIZE, WINDOWSIZE, 0);

  // フィールドの描画
  draw_field();
  // オブジェクトの描画
  draw_object();


  PACMAN pacman_one;

  // パックマンのセットアップを行う
  pacman_one = pacman_Setup(25.0, 25.0, 15.0, 1);

  // アニメーション
  for (;;)
  {
    int layers = HgLSwitch(&dl);
    HgLClear(layers);

    pakuCountOne = pacman_one.paku;

    pacman_one = pacman_KeyIn_one(pacman_one);  // パックマンのキー入力処理
    pacman_one = pacman_Move_one(pacman_one);   // パックマンの移動処理
    pacman_one = pacman_hit_wall(pacman_one);   // 壁当たり判定
    pacman_one = pacman_hit_block(pacman_one);  // ブロック当たり判定
    pacman_one = pacman_hit_center(pacman_one); // 中央ブロック当たり判定


    // パックマン向き判定
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

    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
