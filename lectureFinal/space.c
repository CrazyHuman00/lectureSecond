/**
 * @file space.c
 * @author ASAKURA HIROTO (g2253037@cc.kyoto-su.ac.jp)
 * @brief
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 * 宇宙の3Dゲームを制作した。
 * 中央のキャラを動かして流れてくる緑コアを回収してスコアを稼ぐ。
 * コアは遠近があるため、手前に来る（大きくなる）と当たり判定が発生する。
 * ライフは3で、赤コアに衝突するとライフが1削れるかつスコアが減る。
 * プレイヤーは中央下の黄色い丸で
 *  wキー 上昇 ↑
 *  sキー 下降 ↓
 *  aキー 左  ←
 *  dキー 右  →
 * の処理で移動を行う。
 * ライフが0になるとゲームオーバーでその時のスコアが表示される。
 *
 * できなかった点
 * プレイヤーの立ち位置に赤コアが出現する可能性があるが、対処方法がわからなかった。
 * 構造体をうまくまとめることができなかった。
 *
 *
 */

#include <stdio.h>
#include <handy.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WINDOWSIZE_W (1400.0)
#define WINDOWSIZE_H (700.0)
#define CENTER_X (WINDOWSIZE_W / 2.0)
#define CENTER_Y (WINDOWSIZE_H / 2.0)
#define SLEEPTIME (0.01)
#define LINELONG (200.0)
#define LINELONG_CORE (100.0)
#define COLLISION_RANGE (40.0)

#define CenteredText(layer, x, y, ...)                                 \
  {                                                                    \
    double _dp1, _dp2;                                                 \
    HgWTextSize(layer, &_dp1, &_dp2, __VA_ARGS__);                     \
    HgWText((layer), (x - _dp1 / 2.0), (y - _dp2 / 2.0), __VA_ARGS__); \
  }

/**
 * @brief オブジェクト座標データ
 *
 */
typedef struct POSITION
{
  float x, y, z;
}POSITION;

/**
 * @brief プレイヤー座標データ
 *
 */
typedef struct PLAYER
{
  float x, y, z;
  float dx, dy;
} PLAYER;

/**
 * @brief 最大値最小値を指定してその範囲で乱数生成をする関数
 *
 * @param min
 * @param max
 * @return float
 */
float get_random_in_range(float min, float max)
{
  return ((float)rand() / RAND_MAX) * (max - min) + min;
}

/**
 * @brief playerのセットアップを行う
 *
 * @param x
 * @param y
 * @param z
 * @return PLAYER
 */
PLAYER palyer_setup(float x, float y, float z)
{
  PLAYER player;
  player.x = x;
  player.y = y;
  player.z = z;
  player.dx = 0.0;
  player.dy = 0.0;
  return player;
}

/**
 * @brief playerのキー入力の処理を行う
 *
 * @param player
 * @return PLAYER
 */
PLAYER player_key_in(PLAYER player)
{
  HgSetEventMask(HG_KEY_DOWN);
  hgevent *event = HgEventNonBlocking();

  if (event != NULL)
  {
    if (event->type == HG_KEY_DOWN)
    {
      if (event->ch == 'd')
      {
        player.dx = 3.0;
        player.dy = 0.0;
      }
    }

    if (event->type == HG_KEY_DOWN)
    {
      if (event->ch == 'a')
      {
        player.dx = -3.0;
        player.dy = 0.0;
      }
    }

    if (event->type == HG_KEY_DOWN)
    {
      if (event->ch == 'w')
      {
        player.dx = 0.0;
        player.dy = 3.0;
      }
    }

    if (event->type == HG_KEY_DOWN)
    {
      if (event->ch == 's')
      {
        player.dx = 0.0;
        player.dy = -3.0;
      }
    }
  }

  return player;
}

/**
 * @brief playerの移動処理
 *
 * @param player
 * @return PLAYER
 */
PLAYER player_move(PLAYER player)
{
  player.x += player.dx;
  player.y += player.dy;
  return player;
}

/**
 * @brief player描画関数
 *
 * @param player
 * @param lid
 */
void player_draw(PLAYER player, int lid)
{
  float x = player.x;
  float y = player.y;

  HgWSetColor(lid, HG_YELLOW);
  HgWCircle(lid, x + CENTER_X, y + CENTER_Y, 10);
}

/**
 * @brief 星を描画する関数
 *
 * @param layers
 */
void star_draw(POSITION *p, int layers)
{
  const int starcip = 200;

  for (int i = 0; i < starcip; i++)
    {
      p[i].z -= 0.008;
      if (p[i].z <= 0.0)
      {
        p[i].z = 1.0;
      }
    }

    // 星が奥から手前に流れる処理
    for (int i = 0; i < starcip; i++)
    {
      float size = (1.0 - p[i].z) * 5.0;

      HgWSetFillColor(layers, HG_WHITE);
      HgWCircleFill(layers,
                    p[i].x / p[i].z * CENTER_X + CENTER_X,
                    p[i].y / p[i].z * CENTER_Y + CENTER_Y,
                    size,
                    0);
    }
}

/**
 * @brief Create a cube object
 *
 * @param depth_x
 * @param depth_y
 * @param s
 * @param c
 * @param size
 * @param layers
 */
void create_cube(float depth_x, float depth_y, float s, float c, float size, int layers)
{
  const int vertex = 8;

  struct POSITION cube_p[vertex] = {
      {-1.0, 1.0, -1.0},  // 0
      {-1.0, -1.0, -1.0}, // 1
      {1.0, -1.0, -1.0},  // 2
      {1.0, 1.0, -1.0},   // 3
      {-1.0, 1.0, 1.0},   // 4
      {-1.0, -1.0, 1.0},  // 5
      {1.0, -1.0, 1.0},   // 6
      {1.0, 1.0, 1.0},    // 7
  };

  struct POSITION cube_op[vertex];

  for (int i = 0; i < vertex; i++)
  {
    cube_op[i].x = cube_p[i].x;
    cube_op[i].y = cube_p[i].y * c - cube_p[i].z * s;
    cube_op[i].z = cube_p[i].y * s + cube_p[i].z * c;

    cube_op[i].x /= cube_op[i].z + 4.0;
    cube_op[i].y /= cube_op[i].z + 4.0;
  }

  for (int i = 0; i < 4; i++)
  {
    int j = (i + 1) % 4;

    HgWSetWidth(layers, 3.0);

    HgWLine(layers,
            cube_op[i].x * size + CENTER_X + depth_x,
            cube_op[i].y * size + CENTER_Y + depth_y,
            cube_op[j].x * size + CENTER_X + depth_x,
            cube_op[j].y * size + CENTER_Y + depth_y);

    HgWLine(layers, cube_op[i + 4].x * size + CENTER_X + depth_x,
            cube_op[i + 4].y * size + CENTER_Y + depth_y,
            cube_op[j + 4].x * size + CENTER_X + depth_x,
            cube_op[j + 4].y * size + CENTER_Y + depth_y);

    HgWLine(layers, cube_op[i].x * size + CENTER_X + depth_x,
            cube_op[i].y * size + CENTER_Y + depth_y,
            cube_op[i + 4].x * size + CENTER_X + depth_x,
            cube_op[i + 4].y * size + CENTER_Y + depth_y);
  }
}

/**
 * @brief Create a octahedoron object
 *
 * @param depth_x
 * @param depth_y
 * @param s
 * @param c
 * @param size
 * @param layers
 */
void create_octahedoron(float depth_x, float depth_y, float s, float c, float size, int layers)
{
  const int vertex = 6;

  struct POSITION p[vertex] = {
      {1, 0, -1},  // 0
      {1, 0, 1},   // 1
      {-1, 0, 1},  // 2
      {-1, 0, -1}, // 3
      {0, 1, 0},   // 4
      {0, -1, 0},  // 5
  };

  struct POSITION op[vertex];

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

    HgWLine(layers,
            op[i].x * size + CENTER_X + depth_x,
            op[i].y * size + CENTER_Y + depth_y,
            op[j].x * size + CENTER_X + depth_x,
            op[j].y * size + CENTER_Y + depth_y);

    HgWLine(layers,
            op[i].x * size + CENTER_X + depth_x,
            op[i].y * size + CENTER_Y + depth_y,
            op[4].x * size + CENTER_X + depth_x,
            op[4].y * size + CENTER_Y + depth_y);

    HgWLine(layers,
            op[i].x * size + CENTER_X + depth_x,
            op[i].y * size + CENTER_Y + depth_y,
            op[5].x * size + CENTER_X + depth_x,
            op[5].y * size + CENTER_Y + depth_y);
  }
}

/**
 * @brief main
 *
 * @return int
 */
int main(void)
{
  HgOpen(WINDOWSIZE_W, WINDOWSIZE_H);
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  // 背景を黒く染める
  HgSetFillColor(HG_BLACK);
  HgBoxFill(0, 0, WINDOWSIZE_W, WINDOWSIZE_H, 0);

  // スコア変数
  int score = 0;

  // ライフ変数
  int life = 3;

  // 表示されるオブジェクト数
  int cubeCore = 25;
  int octahedoronCore = 5;

  // 星描画に使う変数
  const int starcip = 200;

  // オブジェクトの移動の変数
  float cube_pos_x[cubeCore];
  float cube_pos_y[cubeCore];
  float cube_pos_z[cubeCore];

  float octahedoron_pos_x[octahedoronCore];
  float octahedoron_pos_y[octahedoronCore];
  float octahedoron_pos_z[octahedoronCore];

  // playerのセットアップ
  PLAYER player;
  player = palyer_setup(0.0, -200.0, 0.5);

  // 角度計算の変数
  float s, c;
  float degree = 0.2;

  struct POSITION p[starcip];

  // 現在初期化して乱数を表示
  srandom(time(NULL));
  // 星の乱数
  for (int i = 0; i < starcip; i++)
  {
    p[i].x = get_random_in_range(-1.0, 1.0); //-1.0~1.0
    p[i].y = get_random_in_range(-0.5, 0.5); //-0.5~0.5
    p[i].z = get_random_in_range(0.0, 1.0);  // 0.0~1.0
  }

  // キューブの乱数
  for (int i = 0; i < cubeCore; i++)
  {
    cube_pos_x[i] = get_random_in_range(-600.0, 600.0);
    cube_pos_y[i] = get_random_in_range(-300.0, 300.0);
    cube_pos_z[i] = get_random_in_range(0.0, 1.0);

    if (cube_pos_x[i] == 0.0)
    {
      cube_pos_x[i] = 300.0;
    }
    if (cube_pos_y[i] == -200.0)
    {
      cube_pos_y[i] = 300.0;
    }
  }

  // コアの乱数
  for (int i = 0; i < octahedoronCore; i++)
  {
    octahedoron_pos_x[i] = get_random_in_range(-600.0, 600.0);
    octahedoron_pos_y[i] = get_random_in_range(-300.0, 300.0);
    octahedoron_pos_z[i] = get_random_in_range(0.0, 1.0);
  }

  // アニメーション
  int layers;
  for (;;)
  {
    layers = HgLSwitch(&dl);
    HgLClear(layers);

    // 星の描画
    star_draw(p, layers);

    // playerの処理
    player = player_key_in(player);
    player = player_move(player);
    player_draw(player, layers);

    // 角度計算を行う
    s = sin(degree);
    c = cos(degree);
    degree += 0.01;

    // キューブが手前から奥に流れる処理
    for (int i = 0; i < cubeCore; i++)
    {
      cube_pos_z[i] -= 0.008;
      if (cube_pos_z[i] <= 0.0)
      {
        cube_pos_z[i] = 1.0;
      }
    }

    // コアが手前から奥に流れる処理
    for (int i = 0; i < octahedoronCore; i++)
    {
      octahedoron_pos_z[i] -= 0.008;
      if (octahedoron_pos_z[i] <= 0.0)
      {
        octahedoron_pos_z[i] = 1.0;
      }
    }

    // キューブの描画を行う
    for (int i = 0; i < cubeCore; i++)
    {
      float cube_size = (1.0 - cube_pos_z[i]) * LINELONG;

      if (player.x <= cube_pos_x[i] + COLLISION_RANGE &&
          player.x >= cube_pos_x[i] - COLLISION_RANGE &&
          player.y <= cube_pos_y[i] + COLLISION_RANGE &&
          player.y >= cube_pos_y[i] - COLLISION_RANGE)
      {
        if (cube_pos_z[i] <= player.z)
        {
          score -= 10;
          life -= 1;
          cube_pos_x[i] = get_random_in_range(-600.0, 600.0);
          cube_pos_y[i] = get_random_in_range(-300.0, 300.0);
          cube_pos_z[i] = 1.0;
        }
      }

      HgWSetColor(layers, HG_RED);
      create_cube(cube_pos_x[i], cube_pos_y[i], s, c, cube_size, layers);
    }

    // コアの描画を行う
    for (int i = 0; i < octahedoronCore; i++)
    {
      float octahedoron_size = (1.0 - octahedoron_pos_z[i]) * LINELONG_CORE;

      if (player.x <= octahedoron_pos_x[i] + COLLISION_RANGE &&
          player.x >= octahedoron_pos_x[i] - COLLISION_RANGE &&
          player.y <= octahedoron_pos_y[i] + COLLISION_RANGE &&
          player.y >= octahedoron_pos_y[i] - COLLISION_RANGE)
      {
        if (octahedoron_pos_z[i] <= player.z)
        {
          score += 20;
          octahedoron_pos_x[i] = get_random_in_range(-600.0, 600.0);
          octahedoron_pos_y[i] = get_random_in_range(-300.0, 300.0);
          octahedoron_pos_z[i] = 1.0;
        }
      }

      HgWSetColor(layers, HG_GREEN);
      create_octahedoron(octahedoron_pos_x[i], octahedoron_pos_y[i], s, c, octahedoron_size, layers);
    }

    if (life <= 0)
    {
      break;
    }

    // スコアの表示
    HgWSetFont(layers, HG_C, 60);
    HgWSetColor(layers, HG_YELLOW);
    HgWText(layers, 10.0, WINDOWSIZE_H - 60.0, "score");
    HgWText(layers, 10.0, WINDOWSIZE_H - 120.0, "%d", score);

    // ライフの表示
    HgWSetFont(layers, HG_C, 60);
    HgWSetColor(layers, HG_PINK);
    HgWText(layers, WINDOWSIZE_W - 300.0, WINDOWSIZE_H - 60.0, "LIFE %d", life);

    HgSleep(SLEEPTIME);
  }

  for (;;)
  {
    layers = HgLSwitch(&dl);
    HgLClear(layers);

    // 星の描画
    star_draw(p, layers);

    HgWSetColor(layers, HG_BLUE);
    HgWSetFont(layers, HG_CB, 80);
    CenteredText(layers, CENTER_X, CENTER_Y, "GAME OVER");
    HgWSetFont(layers, HG_CB, 40);
    CenteredText(layers, CENTER_X, CENTER_Y - 80, "SCORE:%d", score);

    HgSleep(SLEEPTIME);
  }

  HgGetChar();
  HgClose();
  return 0;
}
