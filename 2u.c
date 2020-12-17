#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

void bad_input();
int get_sequence_size();
void get_sequence(int *a, int N);
void repeats_count(int *sequence, int N, int repeats[]);
int maxi(int N, int repeats[]);
void print_result(int N, int repeats[], int max, int *sequence);

int main()
{
    printf("Programa suranda dazniausiai ivestoje skaiciu sekoje pasikartojanti skaiciu/us.\n");
  //getting the size of sequence
    int N = get_sequence_size();
  //allocating memory for sequence
    int *sequence;
    sequence = (int *)malloc(N * sizeof(int));
    if(sequence == NULL)
    {
      printf("Cannot allocate memory.");
      exit(0);
    }
    get_sequence(sequence, N);
  //array to store how many times separate elements appeared
    int repeats[N];
    for(int i = 0; i < N; ++i)
    {
        repeats[i] = 0;
    }
    repeats_count(sequence, N, repeats);
    
  //getting how many repeats were there at most
    int max = maxi(N, repeats);
    
  //printing results
    print_result(N, repeats, max, sequence);
    free(sequence);
    
    return 0;
}


void bad_input()
{
  printf("Klaidinga ivestis!\n");
}

int get_sequence_size()
{
  int N, scnf;
  char new_line;
  do
  {
    printf("Iveskite sekos ilgi (iki %d):", MAX_SIZE);
    scnf = scanf("%d%c", &N, &new_line);
    if(scnf == 0)
    {
      bad_input();
      scanf("%*[^\n]");
    }
    else if ((N <= 0) || (N > MAX_SIZE))
    {
      bad_input();
      scnf = 0;
    }
    else if(new_line != '\n')
    {
      bad_input();
      scanf("%*[^\n]");
      scnf = 0;
    }
  }while(scnf == 0);
  return N;
}

void get_sequence(int *a, int *N)
{
  int scnf = 0;
  char new_line;
    for(int i = 0; i < N; ++i)
    {
      do
      {
        printf("Iveskite %d sveikaji skaiciu: ", i + 1);
        scnf = scanf ("%d%c", a + i, &new_line);
        if(scnf == 0)
        {
            scanf("%*[^\n]");
            bad_input();
        }
        else if(new_line != '\n')
        {
          scanf("%*[^\n]");
          bad_input();
          --i;
        }
      }while(scnf == 0);
    }
}

void repeats_count(int *sequence, int N, int repeats[])
{
  for(int i = 0; i < N - 1; ++i)
  {
    for(int j = i + 1; j < N; ++j)
    {
      if(*(sequence + i) == *(sequence + j) && i != j && *(sequence + i) != -1)
      {
        sequence[j] = -1;
        repeats[i]++;
      }
    }
  }
}

int maxi(int N, int repeats[])
{
  int max = 0;
  for(int i = 0; i < N; i++)
  {
    if(repeats[i] > max)
    {
      max = repeats[i];
    }
  }
  return max;
}
void print_result(int N, int repeats[], int max, int *sequence)
{
    printf("Dazniausiai pasikartojo:\n");
    for(int i = 0; i < N; ++i)
    {
        if(repeats[i] == max)
        {
            printf("%d\n", *(sequence + i));
        }
    }
}
