//HandyGraphicsが開いたら金額を入力する。エンターキーで硬貨が何枚あるか表示される。

#include <stdio.h>
#include <handy.h>

#define CenteredText(layer, x, y, ...)                                 \
  {                                                                    \
    double _dp1, _dp2;                                                 \
    HgWTextSize(layer, &_dp1, &_dp2, __VA_ARGS__);                     \
    HgWText((layer), (x - _dp1 / 2.0), (y - _dp2 / 2.0), __VA_ARGS__); \
  }

#define WINDOWSIZE_W (1000)
#define WINDOWSIZE_H (500)

int main(void)
{
  int window = HgOpen(WINDOWSIZE_W, WINDOWSIZE_H);
  int total = 0;
  int number;
  int count_500, count_100, count_50, count_10, count_5, count_1;

  int img_1 = HgImageLoad("1yen.gif");
  int img_5 = HgImageLoad("5yen.gif");
  int img_10 = HgImageLoad("10yen.gif");
  int img_50 = HgImageLoad("50yen.gif");
  int img_100 = HgImageLoad("100yen.gif");
  int img_500 = HgImageLoad("500yen.gif");

  int count[6] = {count_500, count_100, count_50, count_10, count_5, count_1};
  int price[6] = {500, 100, 50, 10, 5, 1};
  int imgarray[6] = {img_1, img_5, img_10, img_50, img_100, img_500};

  char c = ' ';
  for (;;)
  {
    HgClear();
    HgSetFont(HG_C, 60);
    CenteredText(window, 500, 400, "金額%d円", total);
    c = HgGetChar();

    if (c <= '9' && c >= '0')
    {
      total = total * 10 + (c - '0');
    }

    // push Enterkey
    if (c == 0x0D)
    {
      break;
    }
  }

  for (number = 0; number <= 5; number++)
  {
    count[number] = total / price[number];
    total = total % price[number];
  }

  for (number = 1; number <= 6; number++)
  {
    HgImagePut(130 * number, 100 + (number % 2) * 120, imgarray[number - 1], 0.8, 0);

    HgSetFont(HG_CB, 40);
    HgText(130 * number, 100 + (number % 2) * 120, "%d枚", count[6 - number]);
  }



  HgGetChar();
  HgClose();
  return 0;
}