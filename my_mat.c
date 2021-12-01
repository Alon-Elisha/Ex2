#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_mat.h"


#define n 10

void getmatrix(int matrix1[n][n])
{
  int i,j;
  for(i = 0; i < n ; i++) {
    for(j = 0; j < n;j++) {
        printf("Enter value for matrix[%d][%d]:", i, j);
        scanf("%d", &matrix1[i][j]);
    }
  }
}






int min(int x, int y)
{
  if(x < y)
  {
    return x;
  }
  else
  {
    return y;
  }

}



// IF NEED BE ADD IF i = j return -1
// meanwhile check the code
// if not work define INFINITY as 99999, then work exactly like the code.
int find_if_path(int matrix1[n][n], int x, int y)
{
  int mat[n][n];
  int i,j,k, max;
  max = matrix1[0][0];
  // getting the max value from the matrix.
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(matrix1[i][j] > max)
      {
        max = matrix1[i][j];
      }
    }
  }

  // creating a matrix we can change and tranfrom and copying the matrix we recieved to it.
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      // the change is matrix adding condition
      if(matrix1[i][j] == 0 && i != j)
      {
        // giving a value equivelent to infinity in this scenario.
        // there is no number greater than max, and we arent dealing with extremely large numbers, so max * 3 can be used as 'infinity'.
        // we need infinity for the floyd scenario.
         mat[i][j]  = max * 3;
      }
      else{
        mat[i][j] = matrix1[i][j];
      }
    }
  }

  for(k = 0; k < n; k++)
  {
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
      {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  if(mat[x][y] >= max*3 || mat[x][y] == 0)
  {
    return -1;
  }
  else{
    return mat[x][y];
  }
  
}
















void pathwayexist(int matrix[n][n], int i, int j)
{
  int s = find_if_path(matrix, i, j);
  if(s > -1)
  {
    printf("True\n");
  }
  else{
    printf("False\n");
  }

}



// IF NEED BE ADD IF i = j return -1
// meanwhile check the code
// if not work define INFINITY as 99999, then work exactly like the code.
void shortestpath(int matrix1[n][n], int x, int y)
{
  int mat[n][n];
  int i,j,k, max;
  max = matrix1[0][0];
  // getting the max value from the matrix.
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(matrix1[i][j] > max)
      {
        max = matrix1[i][j];
      }
    }
  }

  // creating a matrix we can change and tranfrom and copying the matrix we recieved to it.
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      // the change is matrix adding condition
      if(matrix1[i][j] == 0 && i != j)
      {
        // giving a value equivelent to infinity in this scenario.
        // there is no number greater than max, and we arent dealing with extremely large numbers, so max * 3 can be used as 'infinity'.
        // we need infinity for the floyd scenario.
         mat[i][j]  = max * 3;
      }
      else{
        mat[i][j] = matrix1[i][j];
      }
    }
  }

  for(k = 0; k < n; k++)
  {
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
      {
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
      }
    }
  }

  if(mat[x][y] >= max*3 || mat[x][y] == 0)
  {
    printf("%d\n", -1);
  }
  else{
    printf("%d\n", mat[x][y]);
  }
  
}




