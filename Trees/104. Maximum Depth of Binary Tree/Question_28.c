#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0; 
    }
    else{
        //traveling with post order
        int leftDepth = maxDepth(root->left);  
        int rightDepth = maxDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1; 
    }
 
}

void printTree(struct TreeNode* root){
    if(root !=NULL){
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

void insertBST(int val, struct TreeNode** root) {
    if (*root == NULL) {
        *root = createNode(val);

    } else if (val < (*root)->val) {
        insertBST(val, &(*root)->left);

    } else if (val > (*root)->val) {
        insertBST(val, &(*root)->right);
        
    } 
   
}
int main() {
    struct TreeNode* root = NULL;

    insertBST(5, &root);
    insertBST(3, &root);
    insertBST(4, &root);
    insertBST(2, &root);
    insertBST(7, &root);
    insertBST(8, &root);
    insertBST(6, &root);
    insertBST(1, &root);
 

    printTree(root);

    int depth;
    depth = maxDepth(root);

    printf("\n%d", depth);

    return 0;
}