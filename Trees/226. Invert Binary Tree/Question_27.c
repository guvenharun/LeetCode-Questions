#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root != NULL){
        struct TreeNode* left = invertTree(root->left);
        struct TreeNode* rigth = invertTree(root->right);

        root->left = rigth;
        root->right = left;
        
    }
    return root;
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct TreeNode* root, int left, int right){
    root->left = createNode(left);
    root->right = createNode(right);
}

int main() {
    struct TreeNode* root = createNode(4);

    insert(root, 2, 7);
    insert(root->left, 1, 3);
    insert(root->right, 6, 9);

    printf("root: %d\n", root->val);
    printf("left child: %d, right child: %d\n", root->left->val, root->right->val);
    printf("left childeren: %d, %d\n", root->left->left->val, root->left->right->val);
    printf("rigth childeren: %d, %d\n", root->right->left->val, root->right->right->val);

    root = invertTree(root);
    
    printf("root: %d\n", root->val);
    printf("left child: %d, right child: %d\n", root->left->val, root->right->val);
    printf("left childeren: %d, %d\n", root->left->left->val, root->left->right->val);
    printf("rigth childeren: %d, %d\n", root->right->left->val, root->right->right->val);

    return 0;
}