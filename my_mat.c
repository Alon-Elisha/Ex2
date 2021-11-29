#include <stdio.h>
#include <stdbool.h>

const int n = 3;

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
  bool flag = true;
  if(matrix[i][j] == 0){
      printf("False");
  }
  else{
      printf("True");
  }


}


int
main (void)
{
  //printf ("Hello, world!\n");
  int i,j, mat[n][n];
  getmatrix(mat);
  printf("Two Dimensional array elements:\n");
  for(i=0; i<n; i++) {
    for(j=0;j<n;j++) {
        printf("%d ", mat[i][j]);
        if(j==3){
          printf("\n");
        }
      }
  }
  printf("\n");
  pathwayexist(mat,1,2);
  printf("\n");
  
}