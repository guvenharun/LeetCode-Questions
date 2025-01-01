#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || (*head).next == NULL) return head;
    
    struct ListNode* current = head;
    struct ListNode* next = (*current).next;

    while((*current).next != NULL){
        if((*current).val == ((*next).val)){
            (*current).next = (*next).next; 
            next = (*next).next;
        }else{
            current = (*current).next;    
            next = (*next).next;
        }
    }
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
    insert(&head, 1);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);

    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    
    current = deleteDuplicates(head);
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