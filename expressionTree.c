// Instructions
// A scientific calculator processes mathematical expression using an Expression Tree (built from postfix notation). Internal nodes store operators (+, -, *, /) while leaves store operands. Implement this in C using a binary tree structure.

// Core Functions
// createNode(char val): Allocate new node
// buildExpressionTree(char* postfix): Construct tree from postfix using stack
// inorder(struct TreeNode* root): Print infix expression (add parentheses)
// evaluate(struct TreeNode* root): Recursively compute result

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* stack[100];
int top = -1;

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct TreeNode* createNode(char val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildExpressionTree(char postfix[])
{
    int i = 0;
    while(postfix[i] != '\0')
    {
        char ch = postfix[i];
        struct TreeNode* node = createNode(ch);
        
        if(isOperator(ch))
        {
            node->right = stack[top--];
            node->left = stack[top--];
        }
        stack[++top] = node;
        i++;
    }
    return stack[top];
}

void inorder(struct TreeNode* root)
{
    if(root != NULL)
    {
        if(isOperator(root->val)) printf("(");
        inorder(root->left);
        printf("%c", root->val);
        inorder(root->right);
        if(isOperator(root->val)) printf(")");
    }
}

int evaluate(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    if(!isOperator(root->val))
        return root->val - '0';
    int left = evaluate(root->left);
    int right = evaluate(root->right);
    switch(root->val)
    {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

int main()
{
    char postfix[] = "23*54*+9-";
    struct TreeNode* root = buildExpressionTree(postfix);
    printf("Infix expression: ");
    inorder(root);
    printf("\nResult: %d", evaluate(root));
    return 0;
}