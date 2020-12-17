#include <stdio.h>

int main(void)
{
  int long number;
  int position = 1, count = 0;
    printf("\nPrograma skaiciuoja, kiek neigiamu skaiciu yra sekos nelyginese pozicijose\n\n");
  do
  {
    int check;
    char character;
    printf("Iveskite %d skaiciu: ", position);
    check = scanf ("%ld%c", &number, &character);

    if (check == 0)
    {
       printf("Klaidinga ivestis!\n");
       scanf("%*[^\n]");
       number = 1;
    }
    else
    {
        if(character == '\n')
        {
            if(position % 2 == 1 && number < 0)
            {
                  ++count;
            }
            ++position;
        }
        else
        {
             printf("Klaidinga ivestis!\n");
             scanf("%*[^\n]");
        }
      }
  }while(number != 0);
    
  if (count > 0)
    {
        printf("\nREZULTATAS\nNeigiamu skaiciu nelyginese pozicijose: %d\n", count);
    }
  else
    {
          printf("\nREZULTATAS\nNeigiamu skaiciu nelyginese pozicijose nera.\n");
    }
  return 0;
}


int i=0;

for (; i<4; )
{
    printf("%d", i);
    //i++;
}
