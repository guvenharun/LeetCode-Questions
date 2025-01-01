#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isMirror(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true; 
    }
    if (left == NULL || right == NULL) {
        return false;
    }

    return (left->val == right->val) && isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true; 
    }

    return isMirror(root->left, root->right);
}

void printTree(struct TreeNode* root){
    if(root != NULL){
        printTree(root->left);
        printf("%d ", root->val);
        printTree(root->right);
    }
}

struct TreeNode* createNode(int value){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL ;

    return newNode;
}

void insert(struct TreeNode* root, int left, int right) {
    if (left != -1) { 
        root->left = createNode(left);
    }
    if (right != -1) { 
        root->right = createNode(right);
    }
}
int main() {
    struct TreeNode* root = createNode(1);

    insert(root, 2, 2);
    insert(root->left, 3, 4);
    insert(root->right, 4, 3);
    
    printTree(root);
    printf("\n");
    
    bool output = isSymmetric(root);
    printf("%d",output);
    

    return 0;
}