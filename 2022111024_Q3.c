// Write a program in C to check if a given vector is an eigenvector for a matrix.
// Save the file as <RollNo>_Q3.c
// Use the following matrix and vector to test your program.
// Matrix = {{1, 2}, {3, 4}}
// Vector = {2, 1}
// Expected Output: The vector is an eigenvector for the matrix.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MATRIX_SIZE 2
#define MAX_ITERATIONS 100
#define EPSILON 1e-6

float absolute(float n)
{
  if (n < 0)
    n = n * -1;
  return n;
}
void matrix_vector_multiply(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE], float result[MATRIX_SIZE])
{
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    result[i] = 0;
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      result[i] += matrix[i][j] * vector[j];
    }
  }
  return;
}

void normalize_vector(float vector[MATRIX_SIZE])
{
  float magnitude = 0;
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    magnitude += vector[i] * vector[i];
  }
  magnitude = sqrt(magnitude);
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    vector[i] /= magnitude;
  }
}

bool is_eigenvector(int matrix[MATRIX_SIZE][MATRIX_SIZE], float vector[MATRIX_SIZE])
{
  float result[MATRIX_SIZE];
  matrix_vector_multiply(matrix, vector, result);
  int flag = 0;
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    if (result[i] != 0)
    {
      flag = 1;
      break;
    }
  }
  if (flag == 0)
    return true; //ensures we never divide by zero during normalizing
  normalize_vector(vector);
  normalize_vector(result);
  if (absolute(result[0] - vector[0]) < EPSILON)
  {
    for (int i = 1; i < MATRIX_SIZE; i++)
    {
      if (absolute(result[i] - vector[i]) >= EPSILON)
        return false;
      return true;
    }
  }
  else if (absolute(result[0] + vector[0]) < EPSILON)
  {
    for (int i = 1; i < MATRIX_SIZE; i++)
    {
      if (absolute(result[i] + vector[i]) >= EPSILON)
        return false;
      return true;
    }
  }
  else
    return false;
}

int main()
{
  int matrix[MATRIX_SIZE][MATRIX_SIZE];
  float vector[MATRIX_SIZE];
  printf("Enter the elements of the matrix:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    for (int j = 0; j < MATRIX_SIZE; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }
  printf("Enter the elements of the vector:\n");
  for (int i = 0; i < MATRIX_SIZE; i++)
  {
    scanf("%f", &vector[i]);
  }

  if (is_eigenvector(matrix, vector))
    printf("The vector is an eigenvector for the matrix.\n");
  else
    printf("The vector is not an eigenvector for the matrix.\n");
  printf("\n");

  return 0;
}
