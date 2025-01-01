#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) { 
    if(head == NULL || head->next == NULL){
        return false;
    }
    struct ListNode* one = head;
    struct ListNode* two = head;
    while(two != NULL && two->next != NULL) {
        one = one->next;
        two = two->next->next;
        if(one == two){

            return true;
        }
    }
    return false;
    
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
int main() {
    struct ListNode* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = head->next; 

    bool result = hasCycle(head);
    printf("Has Cycle: %s\n", result ? "true" : "false");

    tail->next = NULL; 
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}