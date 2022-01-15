/*Operating Systems (CSE231) Refresher Module
Assignment 2, Question 1 Part b*/
/*C program to create a matrix of a size input by the user*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows;
    printf("Enter no of rows: ");
    scanf("%d", &rows);
    printf("\n");

    int *mat[rows];

    int arr[rows];
    
    int i, j;
    for (i = 0; i<rows; i++){
        int columns;
        printf("\nEnter number of columns in row %d: ",i);
        scanf("%d", &columns);
        printf("\n");

        arr[i] = columns;
        mat[i]=(int*)malloc(sizeof(int)*columns);

        for (j = 0; j<columns; j++){
            mat[i][j]=rand() % 9 + 1;
        }
    }

    printf("\n");
    for (i=0;i<rows;i++){
        for (j=0;j<arr[i];j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}