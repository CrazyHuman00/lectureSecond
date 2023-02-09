/**
 * @file hit.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <handy.h>
#include <math.h>
#include "hit.h"

#define WINDOWSIZE (600.0)

/**
 * @brief パックマンの壁の当たり判定
 *
 * @param pacman_one
 * @return PACMAN
 */
PACMAN pacman_hit_wall(PACMAN pacman_one)
{
  if ((pacman_one.y < pacman_one.size && pacman_one.dy < 0.0) ||
      (pacman_one.y > (WINDOWSIZE - pacman_one.size) &&
        pacman_one.dy > 0.0))
  {
    pacman_one.dy *= -1.0;
  }

  if ((pacman_one.x < pacman_one.size && pacman_one.dx < 0.0) ||
      (pacman_one.x > (WINDOWSIZE - pacman_one.size) &&
        pacman_one.dx > 0.0))
  {
    pacman_one.dx *= -1.0;
  }

  return pacman_one;
}

/**
 * @brief パックマンの左ブロックの当たり判定
 *
 * @param pacman_one
 * @return PACMAN
 */
PACMAN pacman_hit_block(PACMAN pacman_one)
{
  // x方向の外側の判定
  if (pacman_one.size + 1.0 > fabs(50.0 - pacman_one.x) ||
      pacman_one.size + 1.0 > fabs(550.0 - pacman_one.x))
  {
    if (pacman_one.y - pacman_one.size < 550.0 &&
        pacman_one.y + pacman_one.size > 350.0)
        {
          pacman_one.dx *= -1.0;
        }

    if (pacman_one.y - pacman_one.size < 250.0 &&
        pacman_one.y + pacman_one.size > 50.0)
        {
          pacman_one.dx *= -1.0;
        }
  }

  // x方向の内側の判定
  if (pacman_one.size + 1.0 > fabs(250.0 - pacman_one.x) ||
      pacman_one.size + 1.0 > fabs(350.0 - pacman_one.x))
  {
    if (pacman_one.y - pacman_one.size < 550.0 &&
        pacman_one.y + pacman_one.size > 400.0)
        {
          pacman_one.dx *= -1.0;
        }

    if (pacman_one.y + pacman_one.size < 200.0 &&
        pacman_one.y + pacman_one.size > 50.0)
        {
          pacman_one.dx *= -1.0;
        }
  }

  // x方向の窪み判定
  if (pacman_one.size + 1.0 > fabs(200.0 - pacman_one.x) ||
      pacman_one.size + 1.0 > fabs(400.0 - pacman_one.x))
  {
    if (pacman_one.y - pacman_one.size < 400.0 &&
        pacman_one.y + pacman_one.size > 350.0)
        {
          pacman_one.dx *= -1.0;
        }

    if (pacman_one.y - pacman_one.size < 250.0 &&
        pacman_one.y + pacman_one.size > 200.0)
        {
          pacman_one.dx *= -1.0;
        }
  }

  // y方向の外側の判定
  if (pacman_one.size + 1.0 > fabs(50.0 - pacman_one.y) ||
      pacman_one.size + 1.0 > fabs(550.0 - pacman_one.y))
  {
    if ((pacman_one.x - pacman_one.size < 250.0 &&
        pacman_one.x + pacman_one.size > 50.0) ||
        (pacman_one.x - pacman_one.size < 550.0 &&
        pacman_one.x + pacman_one.size > 350.0))
        {
          pacman_one.dy *= -1.0;
        }
  }

  // y方向の内側の判定
  if (pacman_one.size + 1.0 > fabs(250.0 - pacman_one.y) ||
      pacman_one.size + 1.0 > fabs(350.0 - pacman_one.y))
  {
    if ((pacman_one.x - pacman_one.size < 200.0 &&
        pacman_one.x + pacman_one.size > 50.0) ||
        (pacman_one.x - pacman_one.size < 550.0 &&
        pacman_one.x + pacman_one.size > 400.0))
        {
          pacman_one.dy *= -1.0;
        }
  }

  // y方向の窪み判定
  if (pacman_one.size + 1.0 > fabs(200.0 - pacman_one.y) ||
      pacman_one.size + 1.0 > fabs(400.0 - pacman_one.y))
  {
    if ((pacman_one.x - pacman_one.size < 250.0 &&
        pacman_one.x + pacman_one.size > 200.0) ||
        (pacman_one.x - pacman_one.size < 400.0 &&
        pacman_one.x + pacman_one.size > 350.0))
        {
          pacman_one.dy *= -1.0;
        }
  }

  return pacman_one;
}

PACMAN pacman_hit_center(PACMAN pacman_one)
{
  // x方向の当たり判定
  if (pacman_one.size + 1.0 > fabs(250.0 - pacman_one.x) ||
      pacman_one.size + 1.0 > fabs(350.0 - pacman_one.x))
  {
    if (pacman_one.y - pacman_one.size < 350.0 &&
        pacman_one.y + pacman_one.size > 250.0)
        {
          pacman_one.dx *= -1.0;
        }
  }

  // y方向の当たり判定
  if (pacman_one.size + 1.0 > fabs(250.0 - pacman_one.y) ||
      pacman_one.size + 1.0 > fabs(350.0 - pacman_one.y))
  {
    if (pacman_one.x - pacman_one.size < 350.0 &&
        pacman_one.x + pacman_one.size > 250.0)
        {
          pacman_one.dy *= -1.0;
        }
  }

  return pacman_one;
}

