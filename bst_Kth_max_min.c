// Instructions
// A university admission system stores student scores in a Binary Search Tree (BST) to quickly find the Kth highest and Kth lowest scoring students for merit lists. Implement both functionalities efficiently.

// Student Scores: 45, 23, 67, 12, 34, 78, 56, 89, 33
// Find: 2nd smallest (23), 3rd largest (67), 4th smallest (45)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int score;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->score = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int score) {
    if (node == NULL)
        return newNode(score);
    if (score < node->score)
        node->left = insert(node->left, score);
    else if (score > node->score)
        node->right = insert(node->right, score);
    return node;
}

void findKth(struct Node* root, int k, int* count, int* result, int mode) {
    if (root == NULL || *count >= k)
        return;
    if (mode == 1)
        findKth(root->right, k, count, result, mode);
    else
        findKth(root->left, k, count, result, mode);
    (*count)++;
    if (*count == k) {
        *result = root->score;
        return;
    }
    if (mode == 1)
        findKth(root->left, k, count, result, mode);
    else
        findKth(root->right, k, count, result, mode);
}

int main() {
    struct Node* root = NULL;
    int scores[] = {45, 23, 67, 12, 34, 78, 56, 89, 33};
    int n = sizeof(scores) / sizeof(scores[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, scores[i]);
    
    int count, result;
    
    count = 0;
    findKth(root, 2, &count, &result, 0);
    printf("2nd Smallest: %d\n", result);
    
    count = 0;
    findKth(root, 3, &count, &result, 1);
    printf("3rd Largest: %d\n", result);
    
    count = 0;
    findKth(root, 4, &count, &result, 0);
    printf("4th Smallest: %d\n", result);
    
    return 0;
}