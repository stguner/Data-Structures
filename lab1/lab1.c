// Suleyman Turker Guner 21YZ0018
// Coded For Data Structures Lecture in Summer School
// 26.07.2022

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define ROW 20
#define COL 20

void RightSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber) // RIGHT SEARCH
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber++;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber][colNumber - temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void LeftSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)   //LEFT SEARCH
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber--;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber][colNumber + temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void BottomSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber) //BOTTOM SEARCH
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      rowNumber++;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;     // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber - temp][colNumber] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void BottomRightSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber++;
      rowNumber++;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber - temp][colNumber - temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void BottomLeftSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber--;
      rowNumber++;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber - temp][colNumber + temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void UpSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      rowNumber--;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber + temp][colNumber] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

void UpRightSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber++;
      rowNumber--;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber + temp][colNumber - temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }

    }
  }
}

void UpLeftSearch(int strlen, char M[ROW][COL], char str[], int rowNumber, int colNumber)
{
  int counter = 0;
  for (int i = 0; i < strlen; i++)
  {
    if (M[rowNumber][colNumber] == str[i])
    {
      counter++;
      colNumber--;
      rowNumber--;
    }
    if (counter == strlen)
    {
      for (int i = 0; i < 15; i++) // SWAP ALL ELEMENTS *
      {
        for (int j = 0; j < 15; j++)
        {
          M[i][j] = '*';
        }
      }
      
      int temp = counter;                 // SWAP * ELEMENTS TO SEARCHED ELEMENTS
      for (int i = 0; i < strlen; i++)
      {
        M[rowNumber + temp][colNumber + temp] = str[i];
        temp--;
      }

      for (int i = 0; i < 15; i++) // PRINT ALL ELEMENTS
      {
        for (int j = 0; j < 15; j++)
        {
          printf("%c", M[i][j]);
        }
        printf("\n");
      }
    }
  }
}

int main()
{
  char M[ROW][COL];
  char temp[ROW][COL];
  char inp1;
  bool isSame = false;
  char str[20];
  int lenghtOfWord; // Lenght of search word

  // CREATE THE PUZZLE

  int i = 0; // FOR WHILE LOOP
  int j = 0;
  int k = 0;
  printf("Puzzle input:");
  printf("\n");

  for (i = 0; i < 15; i++)
  {
    for (j = 0; j <= 29; j++)
    {
      scanf("%c", &inp1);
      temp[i][j] = inp1;
      if (j % 2 == 0)
      {
        M[i][k] = temp[i][j];
        k++;
      }
    }
    j = 0;
    k = 0;
  }

  gets(str);
  lenghtOfWord = strlen(str);

  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      if (str[0] == M[i][j])
      {
        RightSearch(lenghtOfWord, M, str, i, j);
        LeftSearch(lenghtOfWord, M, str, i, j);
        BottomSearch(lenghtOfWord, M, str, i, j);
        BottomRightSearch(lenghtOfWord, M, str, i, j);
        BottomLeftSearch(lenghtOfWord, M, str, i, j);
        UpLeftSearch(lenghtOfWord, M, str, i, j);
        UpRightSearch(lenghtOfWord, M, str, i, j);
        UpSearch(lenghtOfWord, M, str, i, j);
      }
    }
  }
}
