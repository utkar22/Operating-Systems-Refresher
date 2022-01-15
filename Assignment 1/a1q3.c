/*Operating Systems (CSE231) Refresher Module
Assignment 1, Question 3*/
/*C Program to swap two variables and two arrays*/

#include <stdio.h>


int main(int argc, char const *argv[]){
    /*For swapping two variables*/
    /*Assuming the variables to be integer type*/
    int var1;
    int var2;
    int temp;

    /*Taking input*/
    printf("Enter first variable: ");
    scanf("%d",&var1);
    printf("\nEnter second variable: ");
    scanf("%d",&var2);

    /*Swapping*/
    temp = var1;
    var1=var2;
    var2=temp;

    printf("\nAfter swapping, the variables are %d and %d",var1,var2);

    /*For swapping two arrays*/
    /*Get length of array*/
    int len;
    printf("\nEnter length of array: ");
    scanf("%d",&len);

    int arr1[len], arr2[len], temp_arr[len];

    /*Entering elements in the arrays*/
    int i;
    printf("\nEnter elements of the first array: \n");
    for (i = 0; i<len; i++){
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of the second array: \n");
    for (i = 0; i<len; i++){
        scanf("%d", &arr2[i]);
    }

    /*Displaying values*/
    printf("Before swapping: \nFirst Array:");
    for (i=0; i<len; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nSecond Array:");
    for (i=0; i<len; i++){
        printf("%d ", arr2[i]);
    }

    /*Swapping*/
    for (i=0; i<len; i++){
        temp_arr[i]=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp_arr[i];
    }

    /*Displaying after swapping*/
    printf("\n\nAfter swapping: \nFirst Array:");
    for (i=0; i<len; i++){
        printf("%d ", arr1[i]);
    }
    printf("\nSecond Array:");
    for (i=0; i<len; i++){
        printf("%d ", arr2[i]);
    }
    
    return 0;
}