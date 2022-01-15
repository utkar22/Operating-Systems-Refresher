/*Operating Systems (CSE231) Refresher Module
Assignment 1, Question 1*/
/*C program to copy a file from source to destination*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    /*Taking Source File as input*/
    char source_file[100];
    printf("Source file: ");
    scanf("%s",source_file);
    printf("\n");

    /*Opening + Reading file*/
    FILE *input_file = fopen(source_file, "rb");

    if (input_file == NULL){
        printf("File not found.");
        return -1;
    }

    char destination[100];
    /*Taking Source File as input*/
    printf("Destination file: ");
    scanf("%s",destination);
    printf("\n");

    /*Opening Destination File*/
    FILE *output_file = fopen(destination,"wb");

    if (output_file == NULL){
        printf("File not found.");
        return -1;
    }

    char content;

    /*Transfering the content*/
    while (fread((&content),sizeof(char),1,input_file)){
        fwrite(&content,sizeof(char),1,output_file);
    }

    /*Closing Files*/
    fclose(input_file);
    fclose(output_file);

    return 0;
}

