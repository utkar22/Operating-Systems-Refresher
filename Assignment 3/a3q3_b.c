/*Operating Systems (CSE231) Refresher Module
Assignment 3, Question 3 Part b*/


/*C program to create a self balancing Binary Tree (AVL Tree)*/

#include <stdio.h>
#include <stdlib.h>

/*Node Structure*/
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

/*To create a new node*/
struct Node* new_node(int data){
    struct Node *node;
    node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

/*Function to get max of two integers*/
int max(int a, int b){
    if (a>b){
        return (a);
    }
    return (b);
}

/*Function to get height of the tree*/
int height(struct Node *root){
    if (root==NULL){
        return 0;
    }
    return root->height;
}

int balance(struct Node *root){
    if (root==NULL){
        return 0;
    }
    return (height(root->left)-height(root->right));
}

/*To find the minimum element/node */
struct Node* find_min(struct Node *root){
    if (root==NULL){
        return NULL;
    }
    else if(root->left != NULL){
        return find_min(root->left);
    }
    return root;
}

/*Right-Rotate the subtree rooted at y*/
struct Node* right_rotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    //Performing rotation
    x->right = y;
    y->left = T2;

    //Updating the heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

/*Left-Rotate the subtree rooted at x*/
struct Node* left_rotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //Performing rotation
    y->left = x;
    x->right = T2;

    //Updating heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

/*To insert an element in the BST*/
struct Node* insert(struct Node *root, int data){
    if (root==NULL){
        return (new_node(data));
    }
    else if(data<root->data){
        root->left = insert(root->left, data);
    }
    else if(data>root->data){
        root->right = insert(root->right, data);
    }
    else{
        return root;
    }

    root->height = 1 + max(height(root->left),height(root->right));

    int bal = balance(root);

    //Left Case
    if (bal>1){
        if (data>root->left->data){
            root->left = left_rotate(root->left); //Left Right Case
        }
        return right_rotate(root);
    }
    //Right Case
    else if (bal<-1){
        if (data<root->right->data){
            root->right = right_rotate(root->right);
        }
        return left_rotate(root);
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

    root->height = 1 + max(height(root->left),height(root->right));

    int bal = balance(root);

    //Left case
    if (bal>1){
        if (balance(root->left)<0){
            root->left = left_rotate(root->left);    
        }
        return right_rotate(root);
    }
    //Right case
    if (bal<-1){
        if (balance(root->right)>0){
            root->right = right_rotate(root->right);
        }
        return left_rotate(root);
    }

    return root;
}

/*To perform an in-order traversal of the tree*/
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
