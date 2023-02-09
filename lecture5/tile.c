#include <stdio.h>
#include <math.h>

#define BLOCK_SIZE (3)

int main(void)
{
  int numFirst, numSecond;
  int blockDataF[BLOCK_SIZE][BLOCK_SIZE];
  int blockDataS[BLOCK_SIZE][BLOCK_SIZE];


  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      scanf("%d", &blockDataF[numFirst][numSecond]);
    }
  }


  printf("step 0\n");

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      if (blockDataF[numFirst][numSecond] == 1)
      {
        printf(" ■ ");
      }
      else
      {
        printf(" □ ");
      }
    }
    printf("\n");
  }


  //90度回転させる
  printf("step 1\n");

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      blockDataS[numFirst][numSecond] = blockDataF[BLOCK_SIZE - 1 - numSecond][numFirst];
    }
  }

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      if (blockDataS[numFirst][numSecond] == 1)
      {
        printf(" ■ ");
      }
      else
      {
        printf(" □ ");
      }
    }
    printf("\n");
  }


  //180度回転させる
  printf("step 2\n");

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      blockDataF[numFirst][numSecond] = blockDataS[BLOCK_SIZE - 1 - numSecond][numFirst];
    }
  }

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      if (blockDataF[numFirst][numSecond] == 1)
      {
        printf(" ■ ");
      }
      else
      {
        printf(" □ ");
      }
    }
    printf("\n");
  }


  //270度回転させる
  printf("step 3\n");

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      blockDataS[numFirst][numSecond] = blockDataF[BLOCK_SIZE - 1 - numSecond][numFirst];
    }
  }

  for (numFirst = 0; numFirst < BLOCK_SIZE; numFirst++)
  {
    for (numSecond = 0; numSecond < BLOCK_SIZE; numSecond++)
    {
      if (blockDataS[numFirst][numSecond] == 1)
      {
        printf(" ■ ");
      }
      else
      {
        printf(" □ ");
      }
    }
    printf("\n");
  }


  return 0;
}
