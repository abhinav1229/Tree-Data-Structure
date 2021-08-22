/*
    Author :  Abhinav
    Data: 22 August, 2021
    Time:  7:52AM
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

struct btreenode
{
    struct btreenode* leftchild;
    int data;
    struct btreenode* rightchild;
};

/* function protype for insert function to insert node in tree*/
void insert(struct btreenode**, int);
/* function protype for inorder function to traverse in a tree */
void inorder(struct btreenode*);
/* function prototype for preorder function to traverse in tree */
void preorder(struct btreenode*);
/* function prototype for postorder function to traverse in tree */
void postorder(struct btreenode*);
 

/* the main function */
int main()
{
    /* creating a root pointer to struct node type  which will point to the root node of the tree*/
    struct btreenode* bt = NULL;
    /* 
        req -> No. Of node to be inserted
        i -> for iteration
        num -> data to be insertion
    */
    int req, i=1, num;
    
    printf("\nSpecify the number of items to be inserted: ");
    scanf("%d", &req);
    
    /* Iteration throgh loop to insert items in binary search tree */
    while(i++ <= req)
    {
        printf("Enter the data: ");
        scanf("%d", &num);
        insert(&bt, num);
    }
    
    /* printing the inorder traversaln of the tree*/
    printf("\nIn-Order Traversal: \n");
    inorder(bt);
    
    /*printing the preorder traversal of the tree */
    printf("\n\nPre-Order Traversal: \n");
    preorder(bt);
    
    /* priting the postorder traversal of the tree */
    printf("\n\nPost-Order Traversal: \n");
    postorder(bt);
    
    return 0;
}

/* function to insert a node in binary search tree*/
void insert(struct btreenode **sr, int num)
{
    if(*sr == NULL)
    {
        *sr = (struct btreenode*) malloc (sizeof(struct btreenode));
        
        (*sr) -> leftchild = NULL;
        (*sr) -> data = num;
        (*sr) -> rightchild = NULL;
        return;
    }
    /* Search the node to which new node will be attached */
    else 
    {
        if(num < (*sr)->data)
        {
            insert(&((*sr)->leftchild), num);
        }
        else
        {
            insert(&((*sr)->rightchild), num);
        }
        return;
    }
}


/* function for inorder traversing of tree*/
void inorder(struct btreenode* sr)
{
    if(sr != NULL)
    {
        inorder(sr->leftchild);
        printf(" %d ", sr->data);
        inorder(sr->rightchild);
    }
}

/* function for preorder traversing of tree */
void preorder(struct btreenode* sr)
{
    if(sr != NULL)
    {
        printf(" %d ", sr->data);
        preorder(sr->leftchild);
        preorder(sr->rightchild);
    }
}

/* function for postorder traversing of tree */
void postorder(struct btreenode* sr)
{
    if(sr != NULL)
    {
        postorder(sr->leftchild);
        postorder(sr->rightchild);
        printf(" %d ", sr->data);
    }
}
