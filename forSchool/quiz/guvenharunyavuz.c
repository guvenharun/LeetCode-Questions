#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void deleteNode(struct TreeNode **root);
int processLeftMost(struct TreeNode **root);

void printTree(struct TreeNode* root){
    if(root !=NULL){
        printTree(root->left);
        printf("%d ", root->val);
        printTree(root->right);
    }
}

int countLeaf(struct TreeNode* root) {
    if (root == NULL) {
        return 0; 
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->val);
        return 1; 
    }
    return countLeaf(root->left) + countLeaf(root->right);
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
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

void destroy_tree(struct TreeNode* root){
    if(root != NULL){
        destroy_tree(root->left);
        destroy_tree(root->right);
        free(root);
    }
}

//Search algorith for Binary Search Tree's (BST)
struct TreeNode* searchBinary(struct TreeNode* root, int key){
    if(root != NULL){
        if(key == root->val){
            printf("\nfound key value: %d\n",root->val );
            return root;
        }else if(key < root->val){
            return searchBinary(root->left, key);
        }else{
            return searchBinary(root->right, key);
        }
    }
    else return 0;
}

void insertBST( int val, struct TreeNode **root){
    if(*root == NULL){
        *root = createNode(val);

    }else if(val < (*root)->val)
    {
        insertBST(val, &(*root)->left);

    }else if(val > (*root)->val)
    {
        insertBST(val, &(*root)->right);
    }
}
/*------------------------- Deletion From a BST -------------------------*/
void delete( int val, struct TreeNode **root){
    if(*root ==NULL){
        return;
    }else if( val == (*root)->val){
        deleteNode(&(*root));
    }else if( val < (*root)->val){
        delete(val, &(*root)->left);
    }else{
        delete(val, &(*root)->right);
    }
}

void deleteNode(struct TreeNode **root){
    struct TreeNode *deleted;

    if((*root)->left == NULL && (*root)->right == NULL){
        *root = NULL;
        free(*root);
    }

    else if((*root)->left == NULL){
        deleted = *root;
        *root = (*root)->right;
        free(deleted);
        deleted->right = NULL;
    }

    else if((*root)->right == NULL){
        deleted = *root;
        *root = (*root)->left;
        free(deleted);
        deleted->left =NULL;
    }

    else{
        (*root)->val = processLeftMost(&(*root)->right);

    }
}

int processLeftMost(struct TreeNode **root){
    if((*root)->left == NULL){
        int val = (*root)->val;
        struct TreeNode *deleted= *root;
        *root = (*root)->right;
        free(deleted);
        deleted->right = NULL;
        
        return val;
    }else{
        return processLeftMost(&(*root)->left);
    }
}
/*------------------------- Deletion From a BST -------------------------*/
int main() {
    struct TreeNode* root = createNode(4);

    insert(root, 2, 6);
    insert(root->left, 1, 3);
    insert(root->right, 5, 7); 

    printf("Initial Tree: ");
    printTree(root);
    printf("\n");

    int leafCount = countLeaf(root);
    printf("\nLeaf count is: %d", leafCount);

    int key = 6;
    struct TreeNode* search = NULL;
    search = searchBinary(root, key);
    printTree(search);

    struct TreeNode* BST = NULL;
    insertBST(4, &BST);
    insertBST(2, &BST);
    insertBST(5, &BST);
    insertBST(1, &BST);
    insertBST(7, &BST);
    insertBST(6, &BST);
    insertBST(3, &BST);

    printf("\nBinary Search Tree is: ");
    printTree(BST);
    printf("\n");

    printf("Deleting value 2...\n");
    delete(2, &BST);
    printf("Tree after deleting 2: ");
    printTree(BST);
    printf("\n");

    printf("Deleting value 6...\n");
    delete(6, &BST);
    printf("Tree after deleting 6: ");
    printTree(BST);
    printf("\n");

    printf("Deleting value 4...\n");
    delete(4, &BST);
    printf("Tree after deleting 4: ");
    printTree(BST);
    printf("\n");

    return 0;
}
