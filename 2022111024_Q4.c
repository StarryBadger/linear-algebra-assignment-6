/* Write a program in C to find the determinant of a matrix based
on Laplace Expansion Theorem. Choose a matrix of shape 5x5 and you
need to expand using the nth row or column based on your roll number :
n = roll_numbder%5.

If the last digit of your roll number is ODD, Go for Row Expansion,
otherwise go for Column Expansion.
*/

// Save the file as <RollNo>_Q4.c
// Use the following matrix to test your program.
// Matrix = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10},
// {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
// {21, 22, 23, 24, 25}}

#include <stdio.h>
#define MATRIX_SIZE 5
int power(int base, int exp)
{
  if (exp == 0)
    return 1;
  else
    return base * power(base, exp - 1);
}
void get_cofactor(int size, int matrix[size][size], int cofactor[size - 1][size - 1], int p, int q)
{
  int row, column;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (p != i && q != j)
      {
        if (p > i)
          row = i;
        else
          row = i - 1;
        if (q > j)
          column = j;
        else
          column = j - 1;
        cofactor[row][column] = matrix[i][j];
      }
    }
  }
}

int determinant_recursive(int size, int matrix[size][size])
{
  if (size == 1)
    return matrix[0][0];
  int s = 0;
  for (int i = 0; i < size; i++)
  {
    int cofactor[size - 1][size - 1];
    get_cofactor(size, matrix, cofactor, i, 0);
    s += power(-1, i % 2) * matrix[i][0] * determinant_recursive(size - 1, cofactor);
  }
  return s;
}
int laplace_expansion(int matrix[MATRIX_SIZE][MATRIX_SIZE], int n)
{
  int s = 0;
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    int cofactor[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
    get_cofactor(MATRIX_SIZE, matrix, cofactor, i, n);
    s += power(-1, (i + n) % 2) * matrix[i][n] * determinant_recursive(MATRIX_SIZE - 1, cofactor);
  }
  return s;
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  int n;
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("Enter the value of n:\n");
  scanf("%d", &n);
  n = n % 5;
  printf("The determinant of the matrix is %d.\n", laplace_expansion(matrix, n));
  return 0;
}