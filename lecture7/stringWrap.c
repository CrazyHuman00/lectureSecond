#include <stdio.h>
#include <string.h>

#define LASTWORD "end"

int main(void)
{
  char inputShr[100];
  char outputShr[100];

  int count;
  int textCount = 0;
  int textSum = 0;

  for (;;)
  {
    printf("string>>");
    scanf("%s", inputShr);

    if (strcmp(inputShr, LASTWORD) == 0)
    {
      outputShr[textSum - 1] = '\0';
      printf("#%s#\n", outputShr);
      break;
    }

    textCount = strlen(inputShr);

    if (textSum + textCount >= 20)
    {
      printf("#%s#\n", outputShr);

      for (count = 0; count < 100; count++)
      {
        outputShr[count] = '\0';
      }

      textSum = 0;
    }

    strcat(outputShr, inputShr);
    strcat(outputShr, " ");

    textSum += textCount;
    textSum++;
  }

  return 0;
}
