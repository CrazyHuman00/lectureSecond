/**
 * @file object.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <handy.h>
#include <time.h>
#include <stdlib.h>
#include "object.h"

/**
 * @brief オブジェクトを描画する関数
 *
 */
void draw_object()
{
  const int objectPosition = 23;
  int foodPosition = 10;
  int unFoodPosition = objectPosition - foodPosition;

  struct FIELD pos_object[objectPosition] = {
    {25.0, 575.0},
    {25.0, 437.5},
    {25.0, 300.0},
    {25.0, 137.5},

    {137.5, 575.0},
    {137.5, 300.0},
    {137.5, 25.0},

    {300.0, 575.0},
    {300.0, 437.5},
    {300.0, 137.5},
    {300.0, 25.0},

    {437.5, 575.5},
    {437.5, 300.0},
    {437.5, 25.0},

    {575.0, 575.0},
    {575.0, 437.0},
    {575.0, 300.0},
    {575.0, 137.5},
    {575.0, 25.0},

    {225.0, 225.0},
    {225.0, 375.0},
    {375.0, 225.0},
    {375.0, 375.0},
  };

  // 重複しない乱数を生成する
  int i, j, size, tmp;
  int objectArray[objectPosition];
  for (i = 0; i < objectPosition; i++)
  {
    objectArray[i] = i;
  }

  


}
