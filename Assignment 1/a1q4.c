/*Operating Systems (CSE231) Refresher Module
Assignment 1, Question 4*/
/*C Program to reverse a string.*/
#include <stdio.h>

int find_length(char* str){
    /*Finds the length of the string by iterating through each character*/
    int length=0;
    while (str[length]!='\0'){
        ++length;
    }
    return length;
}

void reverse_string(int i, int j, char* str){
    if (i>j){
        return;
    }

    /*Swapping*/
    char temp = str[i];
    str[i]=str[j];
    str[j]=temp;
    reverse_string(i+1,j-1,str);
}

int main(int argc, char const *argv[]){
    char str[1000]; /*Arbritarily chosen*/

    /*Taking string as input*/
    printf("Enter string: ");
    scanf("%s",str);
    
    int len = find_length(str);
    reverse_string(0,len-1,str);

    printf("\nReversed string: %s",str);

    return 0;
}

