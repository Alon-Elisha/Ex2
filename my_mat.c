#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"


#define n 4

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



void pathwayexist(int matrix[n][n], int i, int j)
{
  int s = shortestpath(matrix, i, j);
  if(s > -1)
  {
    printf("True\n");
  }
  else{
    printf("False\n");
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


int shortestpath(int matrix1[n][n], int x, int y)
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
      if(matrix1[i][j] == 0 )
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

  if(mat[x][y] >= max*3)
  {
    return -1;
  }
  else{
    return mat[x][y];
  }
  
}




