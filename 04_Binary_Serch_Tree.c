/*
    Author :  Abhinav
    Data: 22 August, 2021
    Time:  9:31AM
    
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

#define TRUE 1
#define FALSE 0

/* function protype for insert function to insert node in tree*/
void insert(struct btreenode**, int);
/* function prototype for deletion of a node in Binary Search Tree*/
void del(struct btreenode**, int);
/* function prototype to search an element in Binary Search Tree */
void search(struct btreenode**, int, struct btreenode**, struct btreenode**, int*);
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
    
    printf("\n--------------------------\n");
    printf("\nBinary Tree before deletion: \n");
    inorder(bt);
    
    printf("\nEnter element to be delete: ");
    scanf("%d", &num);
    del(&bt, num);
    printf("\nBinary Tree after deletion: \n");
    inorder(bt);
    
    printf("\nEnter element to be delete: ");
    scanf("%d", &num);
    del(&bt, num);
    printf("Binary Tree after deletion: \n");
    inorder(bt);
    
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

/* deletes a node from the binary search tree */
void del(struct btreenode** root, int num)
{
    /* to check item is found or not */
    int found;

    /*
        parent -> for parent node
        x -> for node to be deleted
        xsucc -> for inorder successor node of x node
    */
    struct btreenode* parent, *x, *xsucc;
    
    /* if tree is empty */
    if(*root == NULL)
    {
        printf("Tree is Empty.\n");
        return;
    }
    
    parent = NULL;
    x = NULL;
    
    /* call to search function to find the node to be deleted */
    search(root, num, &parent, &x, &found);
    
    /* if the node to deleted is not found */
    if(found == FALSE)
    {
        printf("Data to be deleted, not found.\n");
        return;
    }
    
    /* if the node to be deleted has two children*/
    if(x->leftchild != NULL && x-> rightchild != NULL)
    {
        printf("\n--- TWO CHILD ---\n");
        parent = x;
        xsucc = x->rightchild;
        
        /* finding inorder successor of node x */
        while(xsucc->leftchild != NULL)
        {
            parent = xsucc;
            xsucc = xsucc -> leftchild;
        }
        x->data = xsucc ->data;
        x = xsucc;
    }
    
    /* if the node to be deleted has no child */
    if(x->leftchild == NULL && x->rightchild == NULL)
    {
        printf("\n--- NO CHILD ---\n");
        if(parent->leftchild == x)
        {
            parent -> leftchild == NULL;
        }
        else 
        {
            parent -> rightchild == NULL;
        }
        
        free(x);
        return;
    }
    
    /* if the node to be deleted has only rightchild */
    if(x->leftchild == NULL && x->rightchild != NULL)
    {
        printf("\n--- RIGHT CHILD ---\n");
        if(parent->leftchild == x)
        {
            parent->leftchild = x->rightchild;
        }
        else
        {
            parent->rightchild = x->rightchild;
        }
        free(x);
        return;
    }
    
    /* if the node to be deleted has only left child */
    if(x->leftchild != NULL && x->rightchild == NULL)
    {
        printf("\n--- LEFT CHILD ---\n");
        if(parent -> leftchild == x)
        {
            parent->leftchild = x->leftchild;
        }
        else
        {
            parent->rightchild = x->leftchild;
        }
        free(x);
        return;
    }
}

/* returns the address of the ndoe to be deleted, address of its parent and whether the node is found or not */
void search(struct btreenode** root, int num, struct btreenode** par, struct btreenode** x, int* found)
{
    struct btreenode *q;
    q = *root;
    *found = FALSE;
    *par = NULL;
    
    while( q != NULL )
    {
        /* if the node to be deleted is found */
        if(q->data == num)
        {
            *found = TRUE;
            *x = q;
            return;
        }
        *par = q;
        
        if(q->data > num)
        {
            q = q->leftchild;
        }
        else
        {
            q = q->rightchild;
        }
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
