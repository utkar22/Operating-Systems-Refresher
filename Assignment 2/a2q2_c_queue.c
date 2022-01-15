/*Operating Systems (CSE231) Refresher Module
Assignment 3, Question 3 Part c*/

/*C program for a Queue using Linked Lists*/
/*We implement Queue using a linked list. Queue follows a LIFO/FILO principle.
Thus we maintain a head pointer. When a new element is enqueued, it is added at
the beginning of the linked list. When the queue is dequeued, the last element
of the linked list is removed.*/

#include <stdio.h>
#include <stdlib.h>


/*Structure for a linked list node*/
struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/*Function to enqueue an element into the queue*/
void enqueue(data){
    //We add a new node behind the head node
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->next = head;
    head=temp;
    return;
}

/*Function to dequeue an element from the queue*/
void dequeue(){
    int popped;
    struct Node *curr = head;
    //If the queue is empty
    if (head==NULL){
        printf("Queue is empty.\n");    
    }
    //In case queue only has a single element
    else if (curr->next==NULL){
        popped = curr->data;
        head = NULL;
        printf("Dequeued element: %d \n",popped);
    }
    else{
        //We first traverse to the node before the tail node
        while (curr->next->next!=NULL){
            curr=curr->next;
        }
        //We free and nullify the tail node. And we get the data and print it
        popped=curr->next->data;
        free(curr->next);
        curr->next = NULL;
        printf("Dequeued element: %d \n",popped);        
    }

}

/*Driver code*/
int main(){
    printf("Operations:\n");
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");
    printf("0 - Exit\n");

    while (1){
        int op;
        printf("Operation: ");
        scanf("%d",&op);    

        if (op==1){
            int data;
            printf("Enter number to be enqueued: ");
            scanf("%d",&data);
            enqueue(data);
        }
        else if (op==2){
            dequeue();
        }
        else{
            printf("Exiting.");
            break;
        }
    }
    return 0;
}