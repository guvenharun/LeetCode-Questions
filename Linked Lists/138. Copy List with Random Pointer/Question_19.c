#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *random;
};

struct ListNode* copyRandomList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

	struct ListNode* copy = (struct ListNode*)malloc(sizeof(struct ListNode));
    copy->val = head->val;
    copy->next =NULL;

    struct ListNode* currentCopy = copy;  
    struct ListNode* temp = head->next;



    while(temp != NULL){
        struct ListNode* tempCopy = (struct ListNode*)malloc(sizeof(struct ListNode));
        tempCopy->val = temp->val;
        tempCopy->next = NULL;

        currentCopy->next = tempCopy;

        temp= temp->next;
        currentCopy = currentCopy->next;
    }

    struct ListNode* mapping[1000]; 
    int index = 0;

    struct ListNode* originalTemp = head;
    while (originalTemp != NULL) {
        mapping[index++] = originalTemp;
        originalTemp = originalTemp->next;
    }

    struct ListNode* copyMapping[1000];
    int copyIndex = 0;
    struct ListNode* copyTemp = copy;

    while (copyTemp != NULL) {
        copyMapping[copyIndex++] = copyTemp;
        copyTemp = copyTemp->next;
    }

    originalTemp = head;
    copyTemp = copy;
    while (originalTemp != NULL) {
        if (originalTemp->random != NULL) {
            int randomIndex = 0;
            while (mapping[randomIndex] != originalTemp->random) {
                randomIndex++;
            }
            copyTemp->random = copyMapping[randomIndex];
        } else {
            copyTemp->random = NULL;
        }

        originalTemp = originalTemp->next;
        copyTemp = copyTemp->next;
    }

    return copy;
}

void insert( struct ListNode** head, int val){
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    (*temp).val = val;
    (*temp).next = NULL;

    if(*head == NULL)
    {
        *head  = temp;
    }
    else{
        struct ListNode* current = *head;
        while ((*current).next != NULL){
            current = (*current).next;
            
        }
        (*current).next = temp; 
    }
}
void createRandom( struct ListNode* node, int index, struct ListNode* head){
    if (index == -1) {
        node->random = NULL;
        return;
    }
    struct ListNode* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    node->random = temp;
}
int main(){
    struct ListNode* head = NULL;

    insert(&head, 7);
    insert(&head, 13);
    insert(&head, 11);
    insert(&head, 10);
    insert(&head, 1);

    createRandom(head, -1, head);
    createRandom(head->next, 0, head);
    createRandom(head->next->next, 4, head);
    createRandom(head->next->next->next, 2, head);
    createRandom(head->next->next->next->next, 0, head);
    
    struct ListNode* current = head;
    while (current != NULL) {
        printf("Node val: %d, Random val: %d\n", current->val, current->random ? current->random->val : -1);
        current = current->next;
    }
    printf("\n");

    struct ListNode* copiedList = copyRandomList(head);    
    current = copiedList;
    while (current != NULL) {
        printf("Node val: %d, Random val: %d\n", current->val, current->random ? current->random->val : -1);
        current = current->next;
    }
    

    
    return 0;
} 

