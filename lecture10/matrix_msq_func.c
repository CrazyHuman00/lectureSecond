#include <stdio.h>

#define MATRIXNUMBER (3)

//魔法陣判定をする関数
int magicFanc(int matrix[][MATRIXNUMBER])
{
  int sumVertical[MATRIXNUMBER] = {0, 0, 0};  //縦判定配列
  int sumBeside[MATRIXNUMBER] = {0, 0, 0};    //横判定配列
  int sumDialog_L = 0;                        //左上斜め判定配列
  int sumDialog_R = 0;                        //右上斜め判定配列
  int i, j;
  int a;

  //判定処理
  for (i = 0; i < MATRIXNUMBER; i++)
  {
    for (j = 0; j < MATRIXNUMBER; j++)
    {
      sumVertical[i] += matrix[j][i];
      sumBeside[i] += matrix[i][j];
    }
    sumDialog_L += matrix[i][i];
    sumDialog_R += matrix[i][MATRIXNUMBER - i - 1];
  }

  a = 1;
  for (i = 0; i < MATRIXNUMBER; i++)
  {
    if (sumVertical[i] != sumBeside[i])
    {
      a = 0;
      break;
    }

    if (sumBeside[i] != sumDialog_L || sumBeside[i] != sumDialog_R)
    {
      a = 0;
      break;
    }
  }

  return a;
}

int main(void)
{
  int matrix[MATRIXNUMBER][MATRIXNUMBER];
  int i, j;

  for (i = 0; i < MATRIXNUMBER; i++)
  {
    for (j = 0; j < MATRIXNUMBER; j++)
    {
      scanf ("%d", &matrix[i][j]);
    }
  }

  int a = magicFanc(matrix);

  if (a == 1)
  {
    printf("Magic Square\n");
  }else{
    printf("Not Magic Square\n");
  }

  return 0;
}
