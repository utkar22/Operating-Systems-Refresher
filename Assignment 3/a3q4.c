/*Operating Systems (CSE231) Refresher Module
Assignment 3, Question 4*/
/*C program to perform Bubble Sort or Selection sort, as per user input*/

#include <stdio.h>

void swap(int *var1, int *var2){
    /*Function to swap two elements*/
    int temp = *var1;
    *var1=*var2;
    *var2=temp;
}

void print_array(int array[], int len){
    /*Function to print an array*/
    int a;
    for (a=0; a<len; a++){
        printf("%d ",array[a]);
    }
    printf("\n");
}

void bubble_sort(int array[], int len){
    /*Function to perform bubble sort*/
    int a, b;
    for (a=0;a<len-1;a++){
        for (b=0; b<len-a-1; b++){
            if (array[b]>array[b+1]){
                swap(&array[b],&array[b+1]);
            }
        }
    }
}

void selection_sort(int array[], int len){
    /*Function to perform selection sort*/
    int a, b, min_id;
    for (a=0;a<len-1;a++){
        min_id=a;
        for (b=a+1;b<len;b++){
            if (array[b]<array[min_id]){
                min_id=b;
            }
        }
        swap(&array[min_id],&array[a]);
    }
}

int main(){
    /*Getting the length of the array*/
    int len;
    printf("\nEnter length of array: ");
    scanf("%d",&len);
    int array[len];

    /*Entering elements in the arrays*/
    int i;
    printf("\nEnter elements of the array (unsorted): \n");
    for (i = 0; i<len; i++){
        scanf("%d", &array[i]);
    }

    /*Printing Unsorted Array*/
    printf("\nUnsorted array: ");
    print_array(array, len);

    /*Getting input from user, whether to run bubble sort or insertion sort. 
    1 for Bubble Sort, 2 for Selection Sort. While loop runs until a valid
    input is give*/
    while (1){
        int which_sort;
        printf("\nEnter 1 for Bubble Sort, Enter 2 for Selection Sort: ");
        scanf("%d", &which_sort);
        printf("\n");

        if (which_sort==1){
            bubble_sort(array, len);
            break;
        }
        else if (which_sort==2){
            selection_sort(array, len);
            break;
        }
        printf("Invalid input.");
    }

    /*Printing the sorted array*/
    printf("Sorted array: ");
    print_array(array,len);
}