/*
    Author :  Abhinav
    Data: 21st August, 2021
    Time: 11:24 PM 
    INDIA
*/

/*
    Including header files
    -> for standard input output : stdio.h
    -> for dynamic memory allocation : stdlib.h
    
*/
#include<stdio.h>
#include<stdlib.h>

/* 
    Creating struture to store data and 
    address of left node and right node
*/

struct node
{
    struct node* left;
    int data;
    struct node* right;
};

/* function protype for buildtree function to built a tree */
struct node* buildtree(int);
/* function protype for inorder function to traverse in a tree */
void inorder(struct node*);
/* function prototype for preorder function to traverse in tree */
void preorder(struct node*);
/* function prototype for postorder function to traverse in tree */
void postorder(struct node*);

/* 
   Creating three arrays:
   1. to store node value
   2. to store index of left child
   3. to store index of right child
*/
char arr[] = {'A', 'B','C','D','E','F','G','\0','\0','H'};
int lc[] = {1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[] = {2,4,6,-1,-1,-1,-1,-1,-1,-1};

/* the main function */
int main()
{
    /* creating a root pointer to struct node type  which will point to the root node of the tree*/
    struct node* root = NULL;
    
    /* calling buildtree function by passing 0 as the first index value*/
    root = buildtree(0);
    
    /* printing the inorder traversaln of the tree*/
    printf("\nIn-Order Traversal: \n");
    inorder(root);
    
    /*printing the preorder traversal of the tree */
    printf("\n\nPre-Order Traversal: \n");
    preorder(root);
    
    /* priting the postorder traversal of the tree */
    printf("\n\nPost-Order Traversal: \n");
    postorder(root);
    
    return 0;
}

/* function to create a binary tree, pass the index of node values array */
struct node* buildtree(int index)
{
    /* creating a pointer 'temp' to struct node*/
    struct node* temp = NULL;
    
    /* Checking if index is not NULL */
    if(index != -1)
    {
        temp = (struct node*) malloc(sizeof(struct node));
        temp -> left = buildtree(lc[index]);
        temp -> data = arr[index];
        temp -> right = buildtree(rc[index]);
    }
    return temp;
}

/* function for inorder traversing of tree*/
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf(" %c ", root->data);
        inorder(root->right);
    }
}

/* function for preorder traversing of tree */
void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf(" %c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* function for postorder traversing of tree */
void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %c ", root->data);
    }
}
