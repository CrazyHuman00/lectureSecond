/**
 * @file hit.h
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once  // 循環読み込みを防ぐ
#include "pacman.h"

/**
 * @brief パックマンの壁の当たり判定
 *
 */
PACMAN pacman_hit_wall(PACMAN pacman_one);

/**
 * @brief パックマンのブロック当たり判定
 *
 */
PACMAN pacman_hit_block(PACMAN pacman_one);

/**
 * @brief パックマンの中央ブロック当たり判定
 *
 */
PACMAN pacman_hit_center(PACMAN pacman_one);
