#include <stdio.h>
#include <handy.h>
#include <string.h>

#define WINDOWSIZE (400)
#define X_START (50.0)
#define Y_START (50.0)

int main(void)
{
  char inputText[100];
  char outputText[2];

  int count, i;

  double x = X_START;
  double y = Y_START;

  scanf("%s", inputText);

  HgOpen(WINDOWSIZE, WINDOWSIZE);

  for (count = 0; count <= 100; count++)
  {
    i = 0;
    if (inputText[count] != '\0')
    {
      outputText[i] = inputText[count];
      HgSetFont(HG_T, 40);
      HgText(x, y, "%s", outputText);
    }
    x += 35;
    y = x;
  }

  HgGetChar();
  HgClose();
  return 0;
}
