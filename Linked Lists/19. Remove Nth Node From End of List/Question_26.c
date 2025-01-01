#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) { 
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* forward = head;  

    for (int i = 0; i < n; i++) {
        if (forward == NULL) { 
            return head;
        }
        forward = forward->next;
    }

    if (forward == NULL) {
        struct ListNode* temp = head;
        head = head->next;
        return head;
    }

    while (forward != NULL) {
        prev = current;
        current = current->next;
        forward = forward->next;
    }

    prev->next = current->next;

    return head;
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
int main(){
    struct ListNode* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    
    current = removeNthFromEnd(head, 3);
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");

    current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }


    return 0;
} 