#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int depth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        // Post-order traversal
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true; 
    }

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
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

void insert(struct TreeNode **root, int value){
    if(*root == NULL){
        *root = createNode(value);
    }
    else if(value > (*root)->val){
        insert(&(*root)->right, value);
    }else{
        insert(&(*root)->left, value);
    }
}
int main() {
    struct TreeNode* root = NULL;

    insert(&root,5);
    insert(&root,2);
    insert(&root,3);
    insert(&root,1);
    insert(&root,7);
    insert(&root,6);
    insert(&root,4);

    printTree(root);

    bool balanced = isBalanced(root);
    printf("\n%d", balanced);

    return 0;
}