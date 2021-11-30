#include <stdio.h>
#include <stdbool.h>
#include "my_mat.h"

#define n 3

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