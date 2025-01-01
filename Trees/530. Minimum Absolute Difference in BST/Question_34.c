#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>  

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void findMinimum(struct TreeNode* root,int* prev, int* minimum){
    if(root == NULL){
        return;
    }

    findMinimum(root->left, prev, minimum);

    if(*prev !=-1){
        int diffirence =  abs(root->val-*prev);

        if (diffirence <*minimum) *minimum = diffirence; 
    }
    *prev = root->val;

    findMinimum(root->right,prev,minimum);
}

int getMinimumDifference(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }else{
        int min =INT_MAX;
        int prev = -1;
        findMinimum(root, &prev, &min);
        return min;
    }
}

void printTree(struct TreeNode* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->val);
        printTree(root->right);
    }
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else if (value > (*root)->val) {
        insert(&(*root)->right, value);
    } else {
        insert(&(*root)->left, value);
    }
}

int main() {
    struct TreeNode* root = NULL;

    // Ağaca eleman ekleme
    insert(&root, 5);
    insert(&root, 11);
    insert(&root, 2);
    insert(&root, 8);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 9);
    insert(&root, 3);
    insert(&root, 10);
    insert(&root, 12);

    printTree(root);
    printf("\n");

    int output = getMinimumDifference(root);
    printf("%d ", output);
    


    return 0;
}
