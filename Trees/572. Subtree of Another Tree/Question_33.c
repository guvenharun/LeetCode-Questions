#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;  
    if (root == NULL || subRoot == NULL) return false; 
    if (root->val != subRoot->val) return false;      

    return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (subRoot == NULL) return true;  
    if (root == NULL) return false; 


    if (isSameTree(root, subRoot)) return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
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
    struct TreeNode* subRoot = NULL;

    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 5);
    insert(&root, 1);
    insert(&root, 3);

    insert(&subRoot,2);
    insert(&subRoot,1);
    insert(&subRoot,3);
    
    printTree(root);
    printf("\n");
    
    printTree(subRoot);
    printf("\n");

    bool output = isSubtree(root, subRoot); 
    printf("%d ", output);

    return 0;
}
