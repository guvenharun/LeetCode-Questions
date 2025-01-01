#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct ListNode* temp = NULL;

    if(list1->val <= list2-> val){
        temp = list1;
        list1 = list1-> next;

    }else{
        temp = list2;
        list2 = list2-> next;
    }

    struct ListNode* head = temp;

    while (list1 != NULL && list2 != NULL){
       
        if(list1->val <= list2-> val)
        {
            temp->next = list1;
            list1 = list1-> next;
        }else{
            temp->next = list2;
            list2 = list2-> next;
        }  
        temp = temp->next;
    } 

    if (list1 != NULL) {
        temp->next = list1;
    } else {
        temp->next = list2;
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
void insertToStart(struct ListNode** head, int val){
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    (*temp).val = val;
    (*temp).next = *head;
    *head = temp;

}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}


int main(){
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    insert(&list1, 1);
    insert(&list1, 2);
    insert(&list1, 4);

    insertToStart(&list2, 4);
    insertToStart(&list2, 3);
    insertToStart(&list2, 1);
      
    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}