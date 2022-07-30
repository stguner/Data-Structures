//Suleyman Turker Guner 21YZ0018
//Coded For Data Structures Lecture in Summer School
//30.07.2022

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define ROW 50
#define COL 50 /* to count number of an asterisk in blob */

int control = 0; 
// A function to check if a given cell (row, col) can be included in depth first search
int isSafe(char M[][COL], int row, int col, bool visited[][COL], int numberOfRow, int numberOfCol)
{
  // row number is in range, column number is in range and value is *     // and not yet visited
  return (row >= 0) && (row < numberOfRow) && (col >= 0) && (col < numberOfCol) && (M[row][col] == '*' && !visited[row][col]);
}
// A utility function to do depth first for a 2D  matrix.

void DepthFirstSearch(char M[][COL], int row, int col, bool visited[][COL], int numberOfRow, int numberOfCol)
{ // These arrays are used to get row and column numbers of 8 neighbours      // of a given cell
  static int rowNumber[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  static int colNumber[] = {-1, 0, 1, -1, 1, -1, 0, 1};
  // Mark this cell as visited
  visited[row][col] = true; // Recur for all connected neighbours
  for (int k = 0; k < 8; ++k)
    if (isSafe(M, row + rowNumber[k], col + colNumber[k], visited, numberOfRow, numberOfCol))
    {
      control++;
      DepthFirstSearch(M, row + rowNumber[k], col + colNumber[k], visited, numberOfRow, numberOfCol);
    }
}
// The main function that returns count of islands in a given boolean
// 2D matrix
int countBlob(int countAsterisk[], char M[][COL], int numberOfRow, int numberOfCol)
{
  // Make a bool array to mark visited cells.      // Initially all cells are unvisited
  bool visited[ROW][COL];
  memset(visited, 0, sizeof(visited));
  // Initialize count as 0 and travese through the all cells of
  // given matrix
  int count = 0;
  for (int i = 0; i < numberOfRow; ++i)
    for (int j = 0; j < numberOfCol; ++j)
      if (M[i][j] == '*' && !visited[i][j]) // If a cell with value * is not
      {                                     // visited yet, then new Blob found
        control = 1;
        DepthFirstSearch(M, i, j, visited, numberOfRow, numberOfCol); // Visit all cells in this island.
        countAsterisk[count] = control;
        ++count; // and increment blob count
      }
  return count;
}


void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


void Sort(int countAsterisk[], int countBlobs)
{
  int i, j, min_idx; // One by one traverse boundary of unsorted subarray
  for (i = 0; i < countBlobs - 1; i++)
  {
    // Find the index of min element in countAsterisk array
    min_idx = i;
    for (j = i + 1; j < countBlobs; j++)
      if (countAsterisk[j] < countAsterisk[min_idx])
        min_idx = j; // Swap the found minimum element with the first element
    swap(&countAsterisk[min_idx], &countAsterisk[i]);
  }
}


// Driver program to test above function
int main()
{
  char M[ROW][COL];
  int countAsterisk[ROW];
  int numberOfRow, numberOfCol;
  int inp1, inp2;
  int countBlobs;
  scanf("%d", &numberOfRow);
  scanf("%d", &numberOfCol);
  while (true)
  {
    scanf("%d", &inp1);
    if (inp1 == -1)
      break;
    scanf("%d", &inp2);
    M[inp1][inp2] = '*';
  }

  countBlobs = countBlob(countAsterisk, M, numberOfRow, numberOfCol);
  Sort(countAsterisk, countBlobs);
  printf("%d ", countBlobs);
  for (int i = 0; i < countBlobs; i++)
  {
    printf("%d ", countAsterisk[i]);
  }
  
  return 0;
  
  
}
