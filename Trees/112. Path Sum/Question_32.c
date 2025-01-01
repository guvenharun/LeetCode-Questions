#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
      return root->val ==targetSum;
    }

    bool left = hasPathSum(root->left, targetSum-root->val);
    bool right = hasPathSum(root->right, targetSum-root->val);

    return left || right; 
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

    bool output = hasPathSum(root,8); 
    printf("%d ", output);

    return 0;
}
