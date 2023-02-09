/**
 * @file field.c
 * @author ASAKURA HIROTO
 * @brief
 * @version 0.1
 * @date 2023-01-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <handy.h>
#include "field.h"

/**
 * @brief フィールドの描画を行う関数
 *
 */
void draw_field()
{
    const int aroundPoint = 6;
    const int centerPoint = 4;
    // 左下のブロック
    struct FIELD pos_left_down[aroundPoint] = {
        {50.0, 50.0},
        {250.0, 50.0},
        {250.0, 200.0},
        {200.0, 200.0},
        {200.0, 250.0},
        {50.0, 250.0},
    };

    // 右下のブロック
    struct FIELD pos_right_down[aroundPoint] = {
        {350.0, 50.0},
        {550.0, 50.0},
        {550.0, 250.0},
        {400.0, 250.0},
        {400.0, 200.0},
        {350.0, 200.0},
    };

    // 左上のブロック
    struct FIELD pos_left_up[aroundPoint] = {
        {50.0, 350.0},
        {200.0, 350.0},
        {200.0, 400.0},
        {250.0, 400.0},
        {250.0, 550.0},
        {50.0, 550.0},
    };

    // 右上のブロック
    struct FIELD pos_right_up[aroundPoint] = {
        {400.0, 350.0},
        {550.0, 350.0},
        {550.0, 550.0},
        {350.0, 550.0},
        {350.0, 400.0},
        {400.0, 400.0},
    };

    // 中央のブロック
    struct FIELD pos_center[centerPoint] = {
        {250.0, 250.0},
        {350.0, 250.0},
        {350.0, 350.0},
        {250.0, 350.0},
    };

    // 色を切り替える
    HgSetColor(HG_SKYBLUE);

    for (int i = 0; i < aroundPoint; i++)
    {
        int j = (i + 1) % 6;

        HgSetWidth(2.0);
        HgLine(pos_left_down[i].x, pos_left_down[i].y,
                pos_left_down[j].x, pos_left_down[j].y);
        HgLine(pos_left_up[i].x, pos_left_up[i].y,
                pos_left_up[j].x, pos_left_up[j].y);
        HgLine(pos_right_down[i].x, pos_right_down[i].y,
                pos_right_down[j].x, pos_right_down[j].y);
        HgLine(pos_right_up[i].x, pos_right_up[i].y,
                pos_right_up[j].x, pos_right_up[j].y);
    }

    for (int i = 0; i < centerPoint; i++)
    {
        int j = (i + 1) % 4;
        HgLine(pos_center[i].x, pos_center[i].y,
                pos_center[j].x, pos_center[j].y);
    }
}
