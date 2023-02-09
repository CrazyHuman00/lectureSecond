#include <stdio.h>
#include <math.h>

#define BINGO_SIZE (3)
#define BINGO_INPUT (5)

int main(void)
{
  int count = 0;
  int numFirst, numSecond;
  int bingodata[BINGO_SIZE][BINGO_SIZE];
  int bingoNumber[BINGO_INPUT];


  int countDiagonalR = 0;
  int countDiagonalL = 0;
  int countVerticalF = 0;
  int countVerticalS = 0;
  int countVerticalT = 0;
  int countBesideF = 0;
  int countBesideS = 0;
  int countBesideT = 0;

  for (numFirst = 0; numFirst < BINGO_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BINGO_SIZE; numSecond++)
    {
      scanf("%d", &bingodata[numFirst][numSecond]);
    }
  }

  for (count = 0; count < BINGO_INPUT; count++)
  {
    scanf("%d", &bingoNumber[count]);
  }

  for (numFirst = 0; numFirst < BINGO_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BINGO_SIZE; numSecond++)
    {
      printf(" %d ", bingodata[numFirst][numSecond]);
    }
    printf("\n");
  }

  printf("---------");
  printf("\n");

  for (count = 0; count < BINGO_INPUT; count++)
  {
    for (numFirst = 0; numFirst < BINGO_SIZE; numFirst++)
    {
      for (numSecond = 0; numSecond < BINGO_SIZE; numSecond++)
      {
        if (bingoNumber[count] == bingodata[numFirst][numSecond])
        {
          bingodata[numFirst][numSecond] = -1;
        }
      }
    }
  }

  for (numFirst = 0; numFirst < BINGO_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BINGO_SIZE; numSecond++)
    {
      if (bingodata[numFirst][numSecond] == -1)
      {
        printf(" . ");
      }
      else
      {
        printf(" %d ", bingodata[numFirst][numSecond]);
      }
    }
    printf("\n");
  }

  for (count = 0; count < 3; count++)
  {
    //横のビンゴ判定
    if (bingodata[0][count] == -1)
    {
      countBesideF++;
    }

    if (bingodata[1][count] == -1)
    {
      countBesideS++;
    }

    if (bingodata[2][count] == -1)
    {
      countBesideT++;
    }

    //縦のビンゴ判定
    if (bingodata[count][0] == -1)
    {
      countVerticalF++;
    }

    if (bingodata[count][1] == -1)
    {
      countVerticalS++;
    }

    if (bingodata[count][2] == -1)
    {
      countVerticalT++;
    }

    //斜めのビンゴ判定
    if (bingodata[count][count] == -1)
    {
      countDiagonalL++;
    }

    if (bingodata[count][2 - count] == -1)
    {
      countDiagonalR++;
    }
  }

  if (countBesideF == 3 || countBesideS == 3 || countBesideT == 3 || countVerticalF == 3 || countVerticalS == 3 || countVerticalT == 3 || countDiagonalL == 3 || countDiagonalR == 3)
  {
    printf("BINGO!\n");
  }
  else
  {
    printf("NOT BINGO\n");
  }

  return 0;
}
