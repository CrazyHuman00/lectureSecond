#include <stdio.h>
#include <math.h>
#include <handy.h>

#define WINDOWSIZE (400.0)
#define XY_JIKU_CENTER (200.0)
#define RASIAN (M_PI / 4)
#define X_MOVE_SPEED (60.0)
#define Y_MOVE_SPEED (40.0)

int main(void)
{
  HgOpen(WINDOWSIZE, WINDOWSIZE);

  HgSetWidth(1.0);
  HgSetColor(HG_BLACK);
  HgLine(5.0, XY_JIKU_CENTER, WINDOWSIZE - 5.0, XY_JIKU_CENTER);
  HgLine(XY_JIKU_CENTER, 5.0, XY_JIKU_CENTER, WINDOWSIZE - 5.0);


  double rasian = RASIAN;
  double moveScore_x = 0.0;
  double moveScore_y = 0.0;
  double x[4] = {-10.0, 30.0, -30.0, 10.0};
  double y[4] = {80.0, 0.0, 0.0, 80.0};
  double s[100] = {};
  double t[100] = {};
  int i_count, j_count;

  HgSetColor(HG_BLUE);


  for (i_count = 0; i_count < 3; i_count++)
  {
    HgLine(x[i_count] + XY_JIKU_CENTER - 150, y[i_count] + XY_JIKU_CENTER - 50, x[i_count + 1] + XY_JIKU_CENTER - 150, y[i_count + 1] + XY_JIKU_CENTER - 50);
  }


  for (j_count = 0; j_count < 4; j_count++)
  {
    moveScore_x += X_MOVE_SPEED;
    moveScore_y += Y_MOVE_SPEED;

    for (i_count = 0; i_count <= 3; i_count++)
    {
      s[i_count] = x[i_count] * cos(rasian) - y[i_count] * sin(rasian);
      t[i_count] = x[i_count] * sin(rasian) + y[i_count] * cos(rasian);
    }

    for (i_count = 0; i_count < 3; i_count++)
    {
      HgLine(s[i_count] + XY_JIKU_CENTER - 150 + moveScore_x, t[i_count] + XY_JIKU_CENTER - 50 + moveScore_y, s[i_count + 1] + XY_JIKU_CENTER - 150 + moveScore_x, t[i_count + 1] + XY_JIKU_CENTER - 50 + moveScore_y);
    }
    rasian += RASIAN;

  }

  HgGetChar();
  HgClose();
  return 0;
}
