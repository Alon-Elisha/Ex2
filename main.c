#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_mat.h"

#define n 10

int
main (void)
{
  /*
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
  */
   //FILE *out_file = fopen("test_files.txt", "w");







   int matrix[n][n];
   bool flag = true;
   bool is_matrix = false;
   char command_letter;
   int i,j;
   while(flag == true)
   {
     printf("Give a command:\n");
     scanf(" %c", &command_letter);
     if(command_letter == 'A')
     {
       is_matrix = true;
     }
     if(is_matrix != true && (command_letter == 'A' || command_letter != 'D'))
     {
        printf("You need to input a matrix before using this command:\n");
        printf("Input matrix\n");
        getmatrix(matrix);
     }
     else{
       if(command_letter == 'A'){
          getmatrix(matrix);
       }
       if(command_letter == 'B'){
          printf("Enter i and j\n");
          scanf("%d" "%d", &i, &j);
          pathwayexist(matrix,i,j);
       }
       if(command_letter == 'C'){
          printf("Enter i and j\n");
          scanf("%d" "%d", &i, &j);
          shortestpath(matrix, i, j);
       }
       if(command_letter == 'D'){
          exit(0);
       }
     }
   }
  
}