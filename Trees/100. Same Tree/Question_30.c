#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    }
    else{
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

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
    struct TreeNode* p = createNode(1);
    struct TreeNode* q = createNode(1);

    insert(p, 2, -1);
    
    insert(q, -1, 2);

    printTree(p);
    printf("\n");
    
    printTree(q);
    printf("\n");

    bool output = isSameTree(p, q);
    printf("%d",output);
    

    return 0;
}