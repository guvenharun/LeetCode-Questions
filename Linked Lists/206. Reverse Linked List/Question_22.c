#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL; 
    struct ListNode* current = head; 
    struct ListNode* next = NULL; 

    while (current != NULL) {
        next = current->next;
        current->next = prev; 
        prev = current;       
        current = next;      
    }

    return prev;
}
struct ListNode* recursiveReverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    else{
        struct ListNode* newHead = recursiveReverseList(head->next); 
        head->next->next = head;
        head->next = NULL;       

        return newHead;  
    }

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
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct ListNode* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    printf("Original list:\n");
    printList(head);

    head = recursiveReverseList(head);
    printf("Recursively reversed list:\n");
    printList(head);


    head = reverseList(head);
    printf("Iteratively reversed list:\n");
    printList(head);


    freeList(head);

    return 0;
}
