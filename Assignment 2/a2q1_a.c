/*Operating Systems (CSE231) Refresher Module
Assignment 2, Question 1 Part a*/
/*C program to create a matrix of a specific size*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *mat[6];
    int arr[6] = {7,4,6,3,7,2};

    int i, j;
    for (i = 0; i<6; i++){
        mat[i]=(int*)malloc(sizeof(int)*arr[i]);
        for (j = 0; j<arr[i]; j++){
            mat[i][j]=rand() % 9 + 1;
        }
    }

    printf("\n");
    for (i=0;i<6;i++){
        for (j=0;j<arr[i];j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}