/**
 * @file pacman.h
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

/**
 * @brief パックマンデータ
 *
 */
typedef struct PACMAN
{
  float x, y;
  float size;
  float dx, dy;
  int paku;
  int change;
} PACMAN;

/**
 * @brief 各種データをセットアップ
 *
 * @return PACMAN
 */
PACMAN pacman_Setup(float x, float y, float size, int change);

/**
 * @brief キー入力の処理を行う
 *
 * @return PACMAN
 */
PACMAN pacman_KeyIn_one(PACMAN pacman_one);

/**
 * @brief player1について移動した後のpac変数を返す
 *
 * @return PACMAN
 */
PACMAN pacman_Move_one(PACMAN pacman_one);

/**
 * @brief パックマン左向き関数
 *
 */
void pacman_left(PACMAN pacman_one, int pakuCount, int lid);

/**
 * @brief パックマン右向き関数
 *
 */
void pacman_right(PACMAN pacman_one, int pakuCount, int lid);

/**
 * @brief パックマン上向き関数
 *
 */
void pacman_up(PACMAN pacman_one, int pakuCount, int lid);

/**
 * @brief パックマン下向き関数
 *
 */
void pacman_down(PACMAN pacman_one, int pakuCount, int lid);



