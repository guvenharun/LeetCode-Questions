#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* temp = head;
    int totalNum= 0;

    while (temp->next != NULL){
        temp = temp->next;
        totalNum++;
    }
    int middleIndex = (totalNum + 1) / 2;
    for(int i=0; i < middleIndex; i++){
        head=head->next;
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
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);

    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
    
    current = middleNode(head);
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