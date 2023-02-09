#include <stdio.h>
#include <math.h>
#include <handy.h>

#define WINDOWSIZE (400.0)
#define XY_JIKU_CENTER (200.0)

int main(void)
{

  int number;
  double x, y;
  double s[100] = {};
  double t[100] = {};
  double ragian;
  double countRagian = 0.0;

  scanf("%lf", &ragian);

  HgOpen(WINDOWSIZE, WINDOWSIZE);

  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, XY_JIKU_CENTER, WINDOWSIZE - 5.0, XY_JIKU_CENTER);
  HgLine(XY_JIKU_CENTER, 5.0, XY_JIKU_CENTER, WINDOWSIZE - 5.0);

  x = 150.0;
  y = 90.0;

  HgSetColor(HG_BLUE);
  HgCircle(x + XY_JIKU_CENTER, y + XY_JIKU_CENTER, 3.0);

  s[0] = x * cos(ragian) - y * sin(ragian);
  t[0] = x * sin(ragian) + y * cos(ragian);


  for (number = 1; countRagian < M_PI - ragian; number++)
  {
    s[number] = s[number - 1] * cos(ragian) - t[number - 1] * sin(ragian);
    t[number] = s[number - 1] * sin(ragian) + t[number - 1] * cos(ragian);

    HgSetColor(HG_RED);
    HgCircle(s[number - 1] + XY_JIKU_CENTER, t[number - 1] + XY_JIKU_CENTER, 3.0);

    countRagian += ragian;
  }

  HgGetChar();
  HgClose();
  return 0;
}