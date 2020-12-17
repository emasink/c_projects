#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256 // stands for maximum character count in a line plus one


int countLines(FILE* inputFile);
void printLongestWord(char * lineArray, FILE* outputFile);
void printShortestWord(char * lineArray, FILE * outputFile);
void readLine(char * lineArray, FILE * inputFile);
void printToFile(int charCount, char * lineArray, FILE * outputFile, int i);



int main(int argc, char * argv[])
{
  printf("Programa saltinio failo kiekvienoje eiluteje suranda ilgiausius ir trumpiausius zodzius ir sukelia juos i isvesties faila\n");

  //asking for viable files
  char source[100];
  char destination[100];
    
  FILE* inputFile;
  FILE* outputFile;
    
  
  int fileCheck = 0; //
  while(fileCheck == 0)
  {
    printf("Nurodykite saltinio tekstini faila: ");
    scanf("%s", source);
    inputFile = fopen(source, "r");
    if(inputFile != NULL)
    {
      fileCheck = 1;
      scanf("%*[^\n]");
    }
    scanf("%*[^\n]");
  }
    
  fileCheck = 0;
  while(fileCheck == 0)
  {
    printf("Nurodykite isvesties tekstini faila: ");
    scanf("%s", destination);
      
    outputFile = fopen(destination, "w");
    if(inputFile != NULL)
    {
      fileCheck = 1;
      scanf("%*[^\n]");
    }
  }
    
  if(inputFile == NULL || outputFile == NULL)
  {
      printf("Neimanoma pasiekti failo\n");
      return -1;
  }
  else
  {
    int lineCount =  countLines(inputFile);
    
      
    
    rewind(inputFile);
    for(int i = 0; i < lineCount; i++)
    {
    //count lines
        char * lineArray = (char * )malloc(MAX_LENGTH * sizeof(char));
        if(lineArray == NULL)
            {
              printf("Nera atminties tekstui issaugoti\n");
              return -1;
            }
    //read one line at a time
      readLine(lineArray, inputFile);
        int charCount = 0;
        printToFile(charCount,lineArray, outputFile, i);
        free(lineArray);
      }
      
  }
  
  
  fclose(inputFile);
  fclose(outputFile);


    return 0;
}

int countLines(FILE* inputFile)
{
  int lineCount = 0;
    char letter;
    while(!feof(inputFile))
    {
      fscanf(inputFile, "%c", &letter);
      fscanf(inputFile, "%*[^\n]");
      ++lineCount;
    }
    return lineCount;
}

void readLine(char * lineArray, FILE * inputFile)
{
    fgets(lineArray, MAX_LENGTH, inputFile);
    if(strlen(lineArray) == MAX_LENGTH - 1)
    {
      fscanf(inputFile, "%*[^\n]%*c");
    }
      for(int i = 0; i < MAX_LENGTH; ++i)
      {
        if(lineArray[i] == '\n')
        {
          lineArray[i] = '\0';
        }
      }
}

void printLongestWord(char * lineArray, FILE* outputFile)
{
  int i, letters, longest = 0;

  for (i = 0; lineArray[i] != '\0'; ++i)
  {
    for (letters = 0; lineArray[i] != '\0' && lineArray[i] != ' '; ++i)
    {
      letters++;
    }
      
    if (letters > longest)
    {
      longest = letters;
    }
  }
    
  for (i = 0; lineArray[i] != '\0'; ++i)
  {
    for (letters = 0; lineArray[i] != '\0' && lineArray[i] != ' '; ++i)
    {
      letters++;
    }

    if(letters == longest)
    {
      int j = i;
      char* printPosition = lineArray + j - longest;
      while(*printPosition != ' ' && *printPosition != '\0')
      {
        fputc(*printPosition, outputFile);
        ++printPosition;
      }
      fputc(' ', outputFile);
    }
  }
  fputc('\n', outputFile);
}

void printShortestWord(char * lineArray, FILE * outputFile)
{
  int shortest = 300, letters;
  for (int i = 0; lineArray[i] != '\0'; ++i)
  {
    for(letters = 0; lineArray[i] != ' ' && lineArray[i] != '\0' && lineArray[i] != '\n'; ++i)
    {
      letters++;
    }
   
    if(letters < shortest && letters != 0)
    {
      shortest = letters;
    }
  }
    
  for (int i = 0; lineArray[i] != '\0'; ++i)
  {
    for (letters = 0; lineArray[i] != '\0' && lineArray[i] != ' '; ++i)
    {
      letters++;
    }

    if(letters == shortest)
    {
      int j = i;
      char* printPosition = lineArray + j - shortest;
      while(*printPosition != ' ' && *printPosition != '\0')
      {
        fputc(*printPosition, outputFile);
        ++printPosition;
      }
      fputc(' ', outputFile);
    }
  }
}
void printToFile(int charCount, char * lineArray, FILE * outputFile, int i)
{
    for(int j = 0; j < strlen(lineArray); ++j)
    {
      if(lineArray[j] != ' ' )
      {
      fprintf(outputFile, "%d.Longest:  ", i + 1);
      printLongestWord(lineArray, outputFile);
      fprintf(outputFile, "  Shortest: ");
      printShortestWord(lineArray, outputFile);
      fputc('\n', outputFile);
      ++charCount;
      break;
      }
    }
    if(charCount == 0)
      {
        fprintf(outputFile, "%d.Empty line\n", i + 1);
      }
}


