#include <stdio.h>
#include <handy.h>
#include <string.h>

#define WINDOWSIZE (480.0)
#define DOTSIZE (12)
#define BLOCKSIZE (40)

int main(void)
{
  HgOpen(WINDOWSIZE, WINDOWSIZE);

  hgevent *event;

  int countF;
  int countS;

  int s, t;
  double x, y;
  double size = WINDOWSIZE / DOTSIZE;
  double dotArray[DOTSIZE][DOTSIZE];

  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);

  HgSetEventMask(HG_MOUSE_DOWN);

  HgSetFillColor(HG_RED);
  HgBoxFill(0, 0, 20, 20, 0);


  //配列の初期化
  for (s = 0; s < 12; s++)
  {
    for (t = 0; t < 12; t++)
    {
      dotArray[t][s] = 0;
    }
  }

  //マウス入力からの白黒反転
  for (;;)
  {
    event = HgEvent();
    if (event->type == HG_MOUSE_DOWN)
    {
      x = event->x;
      y = event->y;

      if (x > 0 && x < 20 && y > 0 && y < 20)
      {
        return 0;
      }

      //タイルの描写
      s = (int)x / BLOCKSIZE;
      t = 12 - ((int)y / BLOCKSIZE);

      if (dotArray[t][s] == 0)
      {
        dotArray[t][s] = 1;

        if (dotArray[t][s] == 1)
        {
          HgSetFillColor(HG_BLACK);
          HgBoxFill(s * BLOCKSIZE, WINDOWSIZE - BLOCKSIZE * t, BLOCKSIZE, BLOCKSIZE, 0);
        }
      }
      else
      {
        HgSetFillColor(HG_WHITE);
        HgBoxFill(s * BLOCKSIZE, WINDOWSIZE - BLOCKSIZE * t, BLOCKSIZE, BLOCKSIZE, 0);
        dotArray[t][s] = 0;
      }

      printf("x=%5.2f, y=%5.2f\n", x, y);
    }
  }

  HgGetChar();
  HgClose();
  return 0;
}
