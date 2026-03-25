// Instructions
// A university library maintains student IDs in a Binary Search Tree (BST) to quickly check membership and book availability. Implement a C program for (i) Binary Search Tree Insertion and Deletion (ii) Binary Tree Traversals. 

// Input 

// Student IDs to insert: 50, 30, 70, 20, 40, 60, 80 

// Book requests: Check 40 (exists), Check 25 (not exists), Delete 30, Insert 90 

// Final traversals: Inorder, Preorder, Postorder 


// Implement Core Functions
// insert(root, value): Insert student ID maintaining BST property
// search(root, value): Return 1 if student exists, 0 otherwise
// deleteNode(root, value): Delete student ID (handle 0-child, 1-child, 2-child cases)
// inorder(root): Print sorted student IDs
// preorder(root): Print preorder traversal
// postorder(root): Print postorder traversal

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL)
        return create(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

int search(struct node* root, int val)
{
    if(root == NULL)
        return 0;

    if(root->data == val)
        return 1;

    if(val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}

struct node* minValue(struct node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int val)
{
    if(root == NULL)
    {
        return root;
    }

    if(val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int i;
    
    for(i = 0; i < 7; i++)
    {
        root = insert(root, arr[i]);
    }
    
    if(search(root, 40))
        printf("40 exists\n");
    else
        printf("40 not found\n");
    
    if(search(root, 25))
        printf("25 exists\n");
    else
        printf("25 not found\n");
    
    root = deleteNode(root, 30);
    root = insert(root, 90);
    
    printf("\nInorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    
    return 0;
}