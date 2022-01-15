/*Operating Systems (CSE231) Refresher Module
Assignment 3, Question 3 Part a*/

/*C program for a Binary Search Tree*/

#include <stdio.h>
#include <stdlib.h>

/*Node Structure*/
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

/*To create a new node*/
struct Node* new_node(int data){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/*To find the minimum element*/
struct Node* find_min(struct Node *root){
    if (root==NULL){
        return NULL;
    }
    else if(root->left != NULL){
        return find_min(root->left);
    }
    return root;
}

/*To insert an element in the BST*/
struct Node* insert(struct Node *root, int data){
    if (root==NULL){
        return (new_node(data));
    }
    else if(data<root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

/*To delete an element from the BST*/
struct Node* delete(struct Node *root, int data){
    if (root==NULL){
        return NULL;
    }
    if (data<root->data){
        root->left = delete(root->left, data);
    }
    else if (data>root->data){
        root->right = delete(root->right, data);
    }
    else{
        /*No Children case*/
        if (root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        /*One Child case*/
        else if (root->left==NULL||root->right==NULL){
            struct Node *temp;
            if (root->left==NULL){
                temp=root->right;
            }
            else{
                temp=root->left;
            }
            free(root);
            return (temp);
        }

        /*Two Children case*/
        else{
            struct Node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    return root;
}

/*To perform an in-order traversal of the BST*/
void inorder_traversal(struct Node *root){
    if (root!=NULL){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

/*To perform a pre-order traversal of the tree*/
void preorder_traversal(struct Node *root){
    if (root!=NULL){
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);   
    }
}

/*Driver code*/
int main(){
    struct Node *root = NULL;

    while (1){
        int to_do;
        printf("\nEnter 0 to exit, 1 to insert, 2 to delete, 3 for pre-order traversal, 4 for in-order traversal: ");
        scanf("%d",&to_do);
        
        if (to_do==1){
            int data;
            printf("Enter data to insert: ");
            scanf("%d",&data);
            root = insert(root, data);
        }
        else if (to_do==2){
            int data;
            printf("Enter data to delete: ");
            scanf("%d",&data);
            root = delete(root, data);
        }
        else if (to_do==3){
            printf("Pre-Order Traversal: ");
            preorder_traversal(root);
        }
        else if (to_do==4){
            printf("In-Order Traversal: ");
            inorder_traversal(root);
        }
        else{
            printf("Exiting.");
            break;
        }
    }

    return 0;
}