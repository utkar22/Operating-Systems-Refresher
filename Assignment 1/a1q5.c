/*Operating Systems (CSE231) Refresher Module
Assignment 1, Question 5*/
/*A C program to run a binary search. 
Note: the array must be sorted*/

#include <stdio.h>

/*Recursive function to run the binary search*/
int binary_search(unsigned int arr[], int l, int r, unsigned int data){
    if (r>=l){
        int mid = l +(r-l)/2; /*Choosing the middle element*/

        if (arr[mid]==data){
            /*If the current middle element is the element we need*/
            return mid;
        }
        if (arr[mid]>data){
            /*If our element is on the left hand side of the middle element*/
            return binary_search(arr, l, mid-1, data);
        }
        /*If our element is on the right hand side of the middle element*/
        return binary_search(arr,mid+1,r,data);
    }
    /*If r<l, then the element is not in the array*/
    return -1;
}

/*Driver code*/
int main(){

    /*Getting the length of the array*/
    int len;
    printf("\nEnter length of array: ");
    scanf("%d",&len);
    unsigned int arr[len];

    /*Entering elements in the arrays*/
    int i;
    printf("\nEnter elements of the array: \n");
    printf("Note: Array must be sorted.\n");
    for (i = 0; i<len; i++){
        scanf("%u", &arr[i]);
    }

    /*Displaying values*/
    printf("Before swapping: \nFirst Array:");
    for (i=0; i<len; i++){
        printf("%u ", arr[i]);
    }

    /*Getting the element to be found*/
    int data;
    printf("\nEnter element to be found: ");
    scanf("%d",&data);

    /*Running the Binary Search*/
    int x;
    x = binary_search(arr, 0, len-1, data);

    /*Displaying the output*/
    if (x==-1){
        printf("\nElement not found in the array.");
    }
    else{
        printf("\nElement found at location %d",x);
    }
    return 0;
}