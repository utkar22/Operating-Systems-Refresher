/*C program to create a Singly Linked List*/

#include <stdio.h>
#include <stdlib.h>

/*Structure for Node*/
struct Node{
    char name[50];
    int roll_no;
    int year_of_joining;
    char academic_program[50];
    struct Node* next;
};

/*Driver code*/
int main(){
    //Declarations
    int count = 0;

    char curr_name[50];
    int curr_roll_no;
    int curr_year_of_joining;
    char curr_academic_program[50];
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* prev;

    int a;

    //While loop runs until user command to exit
    while (1){
        //Takes inputs
        printf("\nEnter roll no: (enter -1 if you want to exit)");
        scanf("%d",&curr_roll_no);

        if (curr_roll_no==-1){
            break;
        }

        printf("\nEnter name: ");
        scanf("%s",&curr_name);

        printf("\nEnter year of joining: ");
        scanf("%d",&curr_year_of_joining);

        printf("\nEnter Academic Program enrolled in: ");
        scanf("%s",curr_academic_program);

        if (count==0){
            //If no head
            head->roll_no = curr_roll_no;
            head->year_of_joining = curr_year_of_joining;

            for (a = 0; a<50; a++){
                head->name[a] = curr_name[a];
                head->academic_program[a] = curr_academic_program[a];
            }

            prev = head;
        }
        else{
            struct Node* curr = (struct Node*)malloc(sizeof(struct Node));

            curr->roll_no = curr_roll_no;
            curr->year_of_joining = curr_year_of_joining;

            //Copying string
            for (a = 0; a<50; a++){
                curr->name[a] = curr_name[a];
                curr->academic_program[a] = curr_academic_program[a];
            }

            prev->next = curr;
            prev = curr;
        }
        count++;

    }

    //To print out all the elements in the linked list
    struct Node* curr_2 = head;

    while (curr_2!=NULL){
        printf("\nRoll no: %d, Name: %s, Year of Joining: %d, Academic Program: %s", curr_2->roll_no, curr_2->name, curr_2->year_of_joining, curr_2->academic_program);
        curr_2 = curr_2->next;
    }
    return 0;
}