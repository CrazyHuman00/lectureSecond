#include <stdio.h>
#include <handy.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "words.h"

#define WINDOW_W_SIZE (1000)
#define WINDOW_H_SIZE (800)
#define SLEEP_TIME (1.0 / 60.0)
#define LASTCOUNT (5)
#define CenteredText(layer, x, y, ...)                                 \
  {                                                                    \
    double _dp1, _dp2;                                                 \
    HgWTextSize(layer, &_dp1, &_dp2, __VA_ARGS__);                     \
    HgWText((layer), (x - _dp1 / 2.0), (y - _dp2 / 2.0), __VA_ARGS__); \
  }

int window;

//説明文
void explain(void)
{
  HgWSetFont(window, HG_CB, 80);
  CenteredText(window, 500, 450, "ごまかしタイピング");
  HgWSetFont(window, HG_C, 30);
  CenteredText(window, 500, 300, "問題文（タイピングする文字）とそれに関係ない画像が表示されるよ");
}

//タイピング処理
void typingFanc(int c, char *string)
{
  hgevent *event;
  doubleLayer dl;
  dl = HgWAddDoubleLayer(0);

  int i, key;
  char word[100] = {""};

  //問題文
  HgWSetFont(window, HG_CB, 30);
  CenteredText(window, 500, 140, questionsN[c]);
  HgWSetFont(window, HG_CB, 40);
  CenteredText(window, 500, 100, questionsJP[c]);

  //入力判定
  for (i = 0; i < strlen(string);)
  {
    event = HgEventNonBlocking();
    int layers = HgLSwitch(&dl);
    key = HgGetChar();
    if (string[i] == key)
    {

      HgLClear(layers);
      word[i] = key;

      HgWSetFont(layers, HG_CB, 50);
      CenteredText(layers, 500, 700, "%s", word);

      i++;
      if (strcmp(word, questionsN[c]) == 0)
      {
        break;
      }
    }
  }
  HgSleep(SLEEP_TIME);
  HgClear();
}


int main(void)
{
  //ウィンドウ
  hgevent *event;
  window = HgOpen(WINDOW_W_SIZE, WINDOW_H_SIZE);

  int a, b, count;
  char type = ' ';

  //説明文の表示
  HgSetFont(HG_CB, 30);
  CenteredText(window, 500, 200, "ENTERでスタート");
  explain();

  for (;;)
  {
    type = HgGetChar();

    //エンターキーを押した後の処理
    if (type == 0x0D)
    {
      HgClear(); //画面をクリア

      for (count = 1; count <= LASTCOUNT; count++)
      {

        //乱数の設定
        srand(time(NULL));
        a = rand() % 60;
        b = rand() % 60;

        typingFanc(a, questionsN[a]);
      }
    }

    if (count >= LASTCOUNT)
    {
      break;
    }
  }

  HgWSetFont(window, HG_CB, 70);
  CenteredText(window, 500, 500, "おつかれ様でした");

  HgGetChar();
  HgClose();
  return 0;
}
